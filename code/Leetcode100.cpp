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
//��ʱ
int climbStairs_tle(int n) {
    int ans=0;
    //��һ��ջģ����
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
//��Ȼ��ʱ
int climbStairs_tle2(int n) {
    //������
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
//��̬�滮
int climbStairs(int n) {
    int p=0;//��i-1
    int q=0;//��i-2
    int ans=1;//��i������ʼ��Ϊ1
    for(int i=1;i<=n;i++)
    {
        p=q;
        q=ans;
        ans=p+q;
    }
    return ans;
}
//169����Ԫ��
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
//234 ��������
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
    //����ָ��
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (!fast)break;
        fast = fast->next;
    }
    //��ת����
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
//338 ����λ����
vector<int> countBits(int n) {
    vector<int> results(n+1);//vector����ʱ����ָ��Ԫ�ظ���
    results[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)//��Ϊż��
            results[i]=results[i/2];
        else//Ϊ����
            results[i]=results[i-1] + 1;
    }
    return results;
}
//448�ҵ�������������ʧ������
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;//δ���ֹ���
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

//461 ��������

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
// 543��������ֱ��
class Solution_543{
    int treeDepth(TreeNode* root)
    {   //�����������
        if(!root)return 0;
        int left=treeDepth(root->left);
        int right=treeDepth(root->right);
        return left>right? left+1: right+1;
    }
    int maxpath(TreeNode* root)
    {   //����ĳ�������������Һ��ӵ���Ⱥ�

        int left_depth=0;
        int right_depth=0;
        //�������������
        left_depth= treeDepth(root->left)-1+1;//��ȼ�һ�õ����������·������1��Ϊ��Զ��㵽���ڵ���·��
        //�������������
        right_depth= treeDepth(root->right)-1+1;//ͬ��
        return left_depth+right_depth;
    }
    void findmax(TreeNode* root,int &max)
    {   //�������α�����㣬��ÿ����������ȺͲ�����max
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
//˼·һ���������ķ���
class Solution_543_better{
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // ���ʵ��սڵ��ˣ�����0
        }
        int L = depth(rt->left); // �����Ϊ�������������
        int R = depth(rt->right); // �Ҷ���Ϊ�������������
        ans = max(ans, L + R + 1); // ����d_node��L+R+1 ������ans
        return max(L, R) + 1; // ���ظýڵ�Ϊ�������������
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
    //���ߣ�LeetCode-Solution
    // ���ӣ�https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/er-cha-shu-de-zhi-jing-by-leetcode-solution/
};

//617�ϲ�������
class Solution_617{
    public:
        void mergeOperation(TreeNode* root1, TreeNode* root2)
        {
            //root2�Ǳ��ϲ�����
            root2->val+=root1->val;//��������Ӧ��㶼���ڣ�ֱ�����
            if(root1->left&&!root2->left)//���������ӽ����ڣ��������ӽ�㲻���ڣ��򽫺��ӽ���Ƶ�����
                root2->left=root1->left;
            //�������ӽ�㲻���ڣ��������ӽ�������ά��ԭ��
            else if(root1->left&&root2->left)//�����������ӽ�㶼���ڣ��ݹ顣
                mergeOperation(root1->left,root2->left);
            if(root1->right&&!root2->right)//ͬ��
                root2->right=root1->right;
            else if(root1->right&&root2->right)
                mergeOperation(root1->right,root2->right);
        }
         TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
         {
             //root2�Ǳ��ϲ�����
             if(!root1)return root2;//���������ڣ�ֱ�ӷ�������
             else if(!root2)
                return root1;//���������ڣ���������
             else
                mergeOperation(root1,root2);//�������ϲ�������
             return root2;

         }


};

//2.�������
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //�ӵ�һλ��ʼ��ӣ��Ȱ���ȫ���洢����������ٴ����λ
    //��l2��ֵ�ӵ�l1
    ListNode* head=l1;

    //ListNode* ans;
    if(!l1)return l2;
    if(!l2)return l1;
    while(1)
    {
        l1->val+=l2->val;
        if(l1->next)
            l1=l1->next;
        else if(!l1->next)
            {l1->next=l2->next;break;}
        if(l2->next)
            l2=l2->next;
        else if(!l2->next)
            break;
    }
    l1=head;
    while(l1)
    {
        if(l1->val>9) {
            if(!l1->next)
            {
                ListNode* temp=new ListNode(0);
                l1->next=temp;
            }
            l1->next->val+=l1->val/10;
            l1->val=l1->val%10;
        }
        l1=l1->next;
    }
    return head;

}
    int main()
{
    int t1[7]={9,9,9,9,9,9,9};
    int t2[4]={9,9,9,9};
    ListNode* l1=new ListNode;
    ListNode* l2=new ListNode;
    ListNode* head=l1;
    for(auto i:t1)
    {
        ListNode* temp=new ListNode(i);
        l1->next=temp;
        l1=l1->next;
    }
    l1=head->next;
    head=l2;
    for(auto i:t2)
    {
        ListNode* temp=new ListNode(i);
        l2->next=temp;
        l2=l2->next;
    }
    l2=head->next;
    ListNode* ans=addTwoNumbers(l1,l2);
    return 0;
}