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

class Solution {
public:
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
};
int main()
{
     MyQueue* myq=new MyQueue();
    myq->push(1);
    myq->push(2);
    int peek=myq->peek();
    int pa=myq->pop();
    bool e=myq->empty();
    return 0;
}