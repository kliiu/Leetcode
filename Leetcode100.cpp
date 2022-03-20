//
// Created by k on 2022/3/10.
//


#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    int main()
{
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(2);
    t.push_back(1);
    ListNode* head;
    ListNode* p=head;
    for(auto i:t)
    {
        p->next=new ListNode(i);
        p=p->next;
    }
   // bool ans=isPalindrome(head->next);
    int a=1,v=2,b=3;
    return 0;
}