//
// Created by k on 2022/2/28.
//

#include <iostream>
#include "stack"
#include "vector"
#include "deque"
using namespace std;
bool pair_brackets(char a,char b)
{   //判断是否能成对
    char front=a;
    char tail=b;
    if(front=='('&&tail==')'||front=='['&&tail==']'||front=='{'&&tail=='}')
        return true;
    return false;
}
bool isValid(string brackets)
{
    stack<int> s;
    for(auto i:brackets)
    {   //当此元素为右括号
        if(i==']'||i==')'||i=='}')
            //栈空，返回false
            {if(s.empty()==1)return false;
            //若栈不为空，判断此元素与栈顶是否成对
            if(pair_brackets(s.top(),i)==1)
                //成对则pop
                s.pop();
            //不成对则false
            else return false;}
        //若为左括号则入栈
        else s.push(i);
    }
    //栈空则说明刚好成对
    return s.empty();
}
class MyQueue {
private:
    stack<int> SimQ;

public:
    MyQueue() {  };

    void push(int x) {
    SimQ.push(x);
    }

    int pop() {
        stack<int> otherQ;
    while(!SimQ.empty())
    {   //将当前队列入另一个栈
        otherQ.push(SimQ.top());
        SimQ.pop();
    }
    int ans=otherQ.top();
    otherQ.pop();
    while(!otherQ.empty()) {
        SimQ.push(otherQ.top());
        otherQ.pop();
    }
    return ans;
    }

    int peek() {
        stack<int> otherQ;
        while(!SimQ.empty())
        {   //将当前队列入另一个栈
            otherQ.push(SimQ.top());
            SimQ.pop();
        }
        int ans=otherQ.top();
        //变回去
        while(!otherQ.empty()) {
            SimQ.push(otherQ.top());
            otherQ.pop();
        }
        return ans;
    }

    bool empty() {
        if(SimQ.empty())return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


    //层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        vector<TreeNode*>thisrow;
        thisrow.push_back(root);
        while(thisrow.empty()!=1)//当前row不为空
        {
            vector<int>temp;
            //将当前层记录，并将下一层的元素依次加入temprow
            vector<TreeNode*>temprow;
            for(auto i:thisrow) {
                temp.push_back(i->val);
                if(i->left)temprow.push_back(i->left);
                if(i->right)temprow.push_back(i->right);
            }
            //将当前层加入ans
            ans.push_back(temp);
            //更新当前层
            thisrow=temprow;
        }
        return ans;
    }

    //104二叉树的最大深度
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int cntL= maxDepth(root->left);
        int cntR= maxDepth(root->right);
        return cntL>cntR?cntL+1:cntR+1;
    }
    //101.对称二叉树
    bool sym(TreeNode* p,TreeNode* q)
    {
        if(!p==!q)return true;
        if(!p||!q)return false;
        return (p->val==q->val&&sym(p->left,q->right)&&sym(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        return sym(root,root);
    }
    //226. 翻转二叉树
    void invert(TreeNode* root)
    {
        if(!root||(!root->left&&!root->right))return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        invert(root->left);
        invert(root->right);
        //翻转结点
    }

    TreeNode* invertTree(TreeNode* root) {
        //if(!root)return NULL;
        invert(root);
        return root;
    }
    //112. 路径总和
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        stack<TreeNode*>visited;
        int sum=0;
        visited.push(root);
        while(visited.empty()!=1)
        {
            TreeNode* temp=visited.top();
            if(!temp->left&&!temp->right)
            {if(temp->val==targetSum)
                    return true;
                else {visited.pop();continue;}
            }
            visited.pop();
            //必须要先判断，push会将空指针入栈造成错误
            if(temp->right)
            {temp->right->val+=temp->val;
                visited.push(temp->right);}
            if(temp->left)
            {temp->left->val+=temp->val;
                visited.push(temp->left);}
        }
        return false;
    }
    //700.二叉搜索树中的搜索
    //迭代
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)return nullptr;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.empty()!=1)
        {
            TreeNode* temp=nodes.top();
            if(temp->val==val)return temp;
            nodes.pop();
            if(temp->right)nodes.push(temp->right);
            if(temp->left)nodes.push(temp->left);

        }
        return nullptr;
    }
    //递归
    TreeNode* searchBST_d(TreeNode* root, int val) {
        if(!root)return nullptr;
        if(root->val==val)return root;
        return val<root->val? searchBST_d(root->left,val):searchBST_d(root->right,val);
    }
//迭代改进
TreeNode* searchBST_improve(TreeNode* root, int val) {
    while(root)
    {
        if(root->val==val)return root;
        if(val<root->val)root=root->left;
        else root=root->right;
    }
    return nullptr;
}
//701. 二叉搜索树中的插入操作
TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * ans=root;
       //空树，返回一个结点
        if(!root) ans=new TreeNode(val);
        while(root)
    {   //若插入值大于当前值
        if(val>root->val)
        {   //若当前结点无右子树直接插入并结束循环
            if(!root->right)
            {   TreeNode *temp=new TreeNode(val);
                root->right=temp;
                break;
            }
            //若当前结点有右子树，更新当前结点为右子树
            else
            {
                root=root->right;
            }
        }//若插入值小于当前值，即对左子树进行处理
        else {
            if(!root->left)
            {
                TreeNode *temp=new TreeNode(val);
                root->left=temp;
                break;
            }
            else root=root->left;
        }
    }
    return ans;

}

//98. 验证二叉搜索树
class Solution {
        long pre = Long.MIN_VALUE;
public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        // 访问左子树
        if (!isValidBST(root.left)) {
            return false;
        }
        // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
        if (root.val <= pre) {
            return false;
        }
        pre = root.val;
        // 访问右子树
        return isValidBST(root.right);
    }
}

int main()
{
    TreeNode * t=new TreeNode(6,new TreeNode(3),new TreeNode(7));
    TreeNode * tree=new TreeNode(5,new TreeNode(4), t);

    bool ans=isValidBST(tree);

    return 0;
}