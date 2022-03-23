//
// Created by k on 2022/3/10.
//


#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//70
//超时
int climbStairs_tle(int n) {
    int ans=0;
    //用一个栈模拟树
    stack<int> tree;
    tree.push(n);
    while(!tree.empty())
    {
        int top=tree.top();
        tree.pop();
        if(top-1==0) {ans++;continue;}
        else tree.push(top-1);
        if(top-2==0) ans++;
        else tree.push(top-2);
    }
    return ans;
}
//仍然超时
int climbStairs_tle2(int n) {
    //暴力？
    int left,right;
    left=right=0;
    if(n-1==0)
        left++;
    else if(n-1>0)
        left=climbStairs_tle2(n-1);
    if(n-2==0)right++;
    else if(n-2>0){right= climbStairs_tle2(n-2);}
    return left+right;
}
//动态规划
int climbStairs(int n) {
    int p=0;//第i-1
    int q=0;//第i-2
    int ans=1;//第i步，初始化为1
    for(int i=1;i<=n;i++)
    {
        p=q;
        q=ans;
        ans=p+q;
    }
    return ans;
}
//169多数元素
int majorityElement(vector<int>& nums) {
    unordered_map<int,int> cnt;
    for(auto i:nums)
    {
        if(cnt.find(i)==cnt.end())cnt[i]=1;
        else if(cnt[i]+1>nums.size()/2)return i;
        else cnt[i]++;
    }
    return nums[0];
}
int majorityElement_b(vector<int>& nums)
{
    int candidate=0;
    int count=0;
    for(auto i:nums)
    {
        if(count==0)candidate=i;
        if(candidate==i)count++;
        else count--;
    }
    return candidate;
}
//234 回文链表
ListNode* reverseList(ListNode* head)
{
    ListNode* temp=head;
    ListNode* pre=NULL;

    while(temp)
    {   ListNode* next=temp->next;
        temp->next=pre;
        pre=temp;
        temp=next;
    }
    return pre;
}
bool isPalindrome(ListNode* head) {
    //快慢指针
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (!fast)break;
        fast = fast->next;
    }
    //反转链表
    slow=reverseList(slow);
    ListNode *temp = head;
    while (slow) {
        if (slow->val != temp->val)return false;
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}

void moveZeroes(vector<int>& nums) {
    int n=nums.size(),left=0,right=0;
    while(right<n)
    {
        if(nums[right]!=0)
        {
            swap(nums[left],nums[right]);
            left++;
        }
        right++;
    }
}
//338 比特位计数
vector<int> countBits(int n) {
    vector<int> results(n+1);//vector创建时可以指定元素个数
    results[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)//若为偶数
            results[i]=results[i/2];
        else//为奇数
            results[i]=results[i-1] + 1;
    }
    return results;
}
//448找到所有数组中消失的数字
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;//未出现过的
    unordered_set<int> exist_nums;
    for (int j = 1; j <= nums.size(); j++)
        exist_nums.emplace(j);
    for(auto i:nums)
    {
            if(exist_nums.find(i)!=exist_nums.end())
                exist_nums.erase(exist_nums.find(i));

    }
    for(auto it=exist_nums.begin();it!=exist_nums.end();it++)
        ans.push_back(*it);
    return ans;
}

//461 汉明距离

int hammingDistance(int x, int y) {
    int t = x^y;
    int  cnt=0;
    while(t!=0)
    {
        //if(t%2!=0)
        //    cnt++;
        cnt += t&1;
        t >>= 1;
    }
    return cnt;
}
// 543二叉树的直径
class Solution_543{
    int treeDepth(TreeNode* root)
    {   //计算树的深度
        if(!root)return 0;
        int left=treeDepth(root->left);
        int right=treeDepth(root->right);
        return left>right? left+1: right+1;
    }
    int maxpath(TreeNode* root)
    {   //对于某个结点计算其左右孩子的深度和

        int left_depth=0;
        int right_depth=0;
        //找右子树的深度
        left_depth= treeDepth(root->left)-1+1;//深度减一得到右子树的最长路径，加1即为最远结点到根节点的最长路径
        //找左子树的深度
        right_depth= treeDepth(root->right)-1+1;//同理
        return left_depth+right_depth;
    }
    void findmax(TreeNode* root,int &max)
    {   //中序依次遍历结点，对每个结点计算深度和并更新max
        if(!root)return;
        findmax(root->left,max);
        if(maxpath(root)>max)max= maxpath(root);
        findmax(root->right,max);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max=0;
        findmax(root,max);
        return max;
    }
};
//思路一样但更简洁的方法
class Solution_543_better{
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
    //作者：LeetCode-Solution
    // 链接：https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/er-cha-shu-de-zhi-jing-by-leetcode-solution/
};

//617合并二叉树
class Solution_617{
    public:
        void mergeOperation(TreeNode* root1, TreeNode* root2)
        {
            //root2是被合并的树
            root2->val+=root1->val;//当两树对应结点都存在，直接相加
            if(root1->left&&!root2->left)//当左树孩子结点存在，右树孩子结点不存在，则将孩子结点移到左树
                root2->left=root1->left;
            //左树孩子结点不存在，右树孩子结点存在则维持原样
            else if(root1->left&&root2->left)//当左右树孩子结点都存在，递归。
                mergeOperation(root1->left,root2->left);
            if(root1->right&&!root2->right)//同上
                root2->right=root1->right;
            else if(root1->right&&root2->right)
                mergeOperation(root1->right,root2->right);
        }
         TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
         {
             //root2是被合并的树
             if(!root1)return root2;//左树不存在，直接返回右树
             else if(!root2)
                return root1;//右树不存在，返回左树
             else
                mergeOperation(root1,root2);//将左树合并到右树
             return root2;

         }


};

    int main()
{
    vector<int> t;
    t.push_back(1);
    //t.push_back(2);
    //t.push_back(4);
    t.push_back(1);

    int ans=__builtin_popcount(1^4);
    return 0;
}