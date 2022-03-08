//
// Created by k on 2022/2/28.
//

#include <iostream>
#include "stack"
#include "vector"
#include "deque"
using namespace std;
bool pair_brackets(char a,char b)
{   //�ж��Ƿ��ܳɶ�
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
    {   //����Ԫ��Ϊ������
        if(i==']'||i==')'||i=='}')
            //ջ�գ�����false
            {if(s.empty()==1)return false;
            //��ջ��Ϊ�գ��жϴ�Ԫ����ջ���Ƿ�ɶ�
            if(pair_brackets(s.top(),i)==1)
                //�ɶ���pop
                s.pop();
            //���ɶ���false
            else return false;}
        //��Ϊ����������ջ
        else s.push(i);
    }
    //ջ����˵���պóɶ�
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
    {   //����ǰ��������һ��ջ
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
        {   //����ǰ��������һ��ջ
            otherQ.push(SimQ.top());
            SimQ.pop();
        }
        int ans=otherQ.top();
        //���ȥ
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


    //�������
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        vector<TreeNode*>thisrow;
        thisrow.push_back(root);
        while(thisrow.empty()!=1)//��ǰrow��Ϊ��
        {
            vector<int>temp;
            //����ǰ���¼��������һ���Ԫ�����μ���temprow
            vector<TreeNode*>temprow;
            for(auto i:thisrow) {
                temp.push_back(i->val);
                if(i->left)temprow.push_back(i->left);
                if(i->right)temprow.push_back(i->right);
            }
            //����ǰ�����ans
            ans.push_back(temp);
            //���µ�ǰ��
            thisrow=temprow;
        }
        return ans;
    }

    //104��������������
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int cntL= maxDepth(root->left);
        int cntR= maxDepth(root->right);
        return cntL>cntR?cntL+1:cntR+1;
    }
    //101.�Գƶ�����
    bool sym(TreeNode* p,TreeNode* q)
    {
        if(!p==!q)return true;
        if(!p||!q)return false;
        return (p->val==q->val&&sym(p->left,q->right)&&sym(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        return sym(root,root);
    }
    //226. ��ת������
    void invert(TreeNode* root)
    {
        if(!root||(!root->left&&!root->right))return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        invert(root->left);
        invert(root->right);
        //��ת���
    }

    TreeNode* invertTree(TreeNode* root) {
        //if(!root)return NULL;
        invert(root);
        return root;
    }
    //112. ·���ܺ�
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
            //����Ҫ���жϣ�push�Ὣ��ָ����ջ��ɴ���
            if(temp->right)
            {temp->right->val+=temp->val;
                visited.push(temp->right);}
            if(temp->left)
            {temp->left->val+=temp->val;
                visited.push(temp->left);}
        }
        return false;
    }
    //700.�����������е�����
    //����
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
    //�ݹ�
    TreeNode* searchBST_d(TreeNode* root, int val) {
        if(!root)return nullptr;
        if(root->val==val)return root;
        return val<root->val? searchBST_d(root->left,val):searchBST_d(root->right,val);
    }
//�����Ľ�
TreeNode* searchBST_improve(TreeNode* root, int val) {
    while(root)
    {
        if(root->val==val)return root;
        if(val<root->val)root=root->left;
        else root=root->right;
    }
    return nullptr;
}
//701. �����������еĲ������
TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * ans=root;
       //����������һ�����
        if(!root) ans=new TreeNode(val);
        while(root)
    {   //������ֵ���ڵ�ǰֵ
        if(val>root->val)
        {   //����ǰ�����������ֱ�Ӳ��벢����ѭ��
            if(!root->right)
            {   TreeNode *temp=new TreeNode(val);
                root->right=temp;
                break;
            }
            //����ǰ����������������µ�ǰ���Ϊ������
            else
            {
                root=root->right;
            }
        }//������ֵС�ڵ�ǰֵ���������������д���
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

//98. ��֤����������
class Solution {
        long pre = Long.MIN_VALUE;
public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        // ����������
        if (!isValidBST(root.left)) {
            return false;
        }
        // ���ʵ�ǰ�ڵ㣺�����ǰ�ڵ�С�ڵ������������ǰһ���ڵ㣬˵��������BST������ false���������������
        if (root.val <= pre) {
            return false;
        }
        pre = root.val;
        // ����������
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