//
// Created by k on 2022/3/10.
//


#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
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

//2.两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //从第一位开始相加，先把数全部存储起来，最后再处理进位
    //将l2的值加到l1
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
//3 最长不重复子串
int lengthOfLongestSubstring(string s) {
    int max=0;
    unordered_map<char,int> had;
    vector<char>::iterator it;
    int start=0;

    for(int i=0;i<s.size();i++)
    {
        if(had.find(s[i])!=had.end()&&had[s[i]]>=start)
        {
            start=had[s[i]]+1;
        }
        had[s[i]]=i;
        if(i-start+1>max)
            max=i-start+1;
    }
    return max;
}
//5. 最长回文子串
string longestPalindrome(string s) {
    if(s.size()<2)return s;
    int n=s.size();
    int maxlen=1;//n>=1
    int begin=0;
    vector<vector<int>> dp(n,vector<int>(n));//dp[i][j]表示s[i:j]是否是回文串
    for(int i=0;i<n;i++)
    {
        dp[i][i]=true;//一个字符为回文串
    }
    for(int L=2;L<=n;L++)//L为串的长度
    {//左值为i，右值为j,L=j-i+1;
        for(int i=0;i<n;i++)
        {
            int j=L+i-1;
            if(j>=n)break;//不符合条件，右边界越界

            if(s[j]==s[i])//若对应值相等
            {   if(L-1<4)
                dp[i][j]=true;//当对应值相等且长度小于4，说明为回文串
                else dp[i][j]=dp[i+1][j-1];//否则若字串为回文串则为回文串
            }
            else dp[i][j]=false;

            //判断回文
            if(dp[i][j]==true&&L>maxlen)
            {
                maxlen=L;
                begin=i;
            }

        }

    }
    return s.substr(begin, maxlen);

}
//11. 盛最多水的容器
class Solution_11 {
public:
    int maxArea_TLE(vector<int>& height) {
        int max=0;
        for(int i =0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {   int min=height[i]>height[j]?height[j]:height[i];
                if((j-i)*min>max)max=(j-i)*min;
            }
        }
        return max;
    }

    int maxArea(vector<int>& height) {
        int max=0;
        int i=0;int j=height.size()-1;
        while(i!=j)
        {
            int min=height[i]>height[j]?height[j]:height[i];
            if((j-i)*min>max)max=(j-i)*min;
            if(height[i]>height[j])j--;
            else i++;
        }
        return max;
    }
};

//三数之和
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size();i++)
    {   if(i>0&&nums[i]==nums[i-1])
            continue;//跳到与上一个元素不等的元素
        int third=nums.size()-1;//应-1
        for(int j=i+1;j<nums.size();j++)
        {   if(j>i+1&&nums[j]==nums[j-1])//跳到与上一个元素不等的元素
                continue;

            while(third>j&&nums[i]+nums[j]+nums[third]>0)
            {
                third--;//保证j在third右边
            }
            if(third==j)break;
            if(nums[i]+nums[j]+nums[third]==0)
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[third]);
                ans.push_back(temp);
            }
        }
    }
    return  ans;
}
//17. 电话号码的字母组合
class Solution_17 {
public:
    vector<string> letterCombinations(string digits) {
        //map映射字母和数字
        unordered_map<char,vector<string>> phone;
        phone['2']={"a","b","c"};
        phone['3']={"d","e","f"};
        phone['4']={"g","h","i"};
        phone['5']={"j","k","l"};
        phone['6']={"m","n","o"};
        phone['7']={"p","q","r","s"};
        phone['8']={"t","u","v"};
        phone['9']={"w","x","y","z"};

        vector<string>ans;
        for(auto i:digits )
        {   //对每个数字循环
            if(ans.empty())
            {
                ans=phone[i];//第一个字母直接全部push
                continue;
            }
            //int size=phone[i].size();//当前数字对应几个数字
            vector<string> temp=ans;
            ans.clear();
            for(auto j:temp)
            {
                for (auto k: phone[i])
                {//对每个数字对应的字母都要出现
                    ans.push_back(j+k);
                }
            }
        }
        return ans;
    }

};
//19. 删除链表的倒数第 N 个结点
class Solution {
public:
    ListNode* removeNthFromEnd_1(ListNode* head, int n) {
        //不是直接删？
        ListNode* current=head;
        int cnt=0;
        while(current)//
        {
            current=current->next;
            cnt++;//计算共有多少个节点
        }

        int del=cnt-n;//要删除的节点位置
        if(del==0)return head->next;
        current=head;
        while(del-1>0)//移动到前一个时停止
        {
            current=current->next;
            del--;
        }

        //if(!current->next)return  nullptr;//若要被删除的点不存在
        //else
        current->next=current->next->next;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针
        ListNode* fast=head;
        ListNode* dummy=new ListNode(0,head);
        ListNode* slow=dummy;//指向head前一个,可以避免要删除头节点引发的错误
        //先将fast遍历n个节点，使其与slow相差n个节点。
        //再同时遍历fast，slow，当fast为空，slow则指向倒数第n个节点
        for(int i = 0;i<n;i++)
        {
            fast=fast->next;
        }
        //同时遍历
        while(fast)//当fast指向最后一个，slow指向要删除的前一个结点
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        ListNode* ans=dummy->next;
        delete dummy;
        return ans;
    }
};

//22. 括号生成
class Solution_22{
public:
    vector<string> generateParenthesis(int n) {
        int left=n;
        int right=n;
        vector<string> ans;
        //用树来模拟
        //0表示左括号，1表示右括号
        if(!n)return ans;
        TreeNode* parenthesis=new TreeNode('(');
        left--;

        //对树进行遍历，得到答案
        string a="";
        generateTree(parenthesis,left,right,a, ans);
        //销毁树
        deleteTree(parenthesis);
        //ansTree(parenthesis,a,ans);
        return ans;
    }
    void generateTree(TreeNode* t, int left, int right,string s,vector<string>&ans)
    {
        //对每个结点进行判断，当前若还有left则插入一个左节点，有right则插入一个右节点
        //同时对left,right-1
        //if(t==NULL)return;
        //中序遍历
        s+=t->val;//添加括号
        if(!left&&!right){ans.push_back(s);return;}//无可用括号，则将当前字符串加入答案并返回
        int current_left=left;
        int current_right=right;
        if(current_left>0)//有右括号剩余，添加右括号
        {
            t->left=new TreeNode('(');
            current_left--;
            generateTree(t->left,current_left,right,s,ans);
        }
        if(current_right>0&&left<right)//当剩余可用右括号小于剩余左括号，说明已有右括号大于左括号时，才能插入左括号
        {
            t->right=new TreeNode(')');
            current_right--;
            generateTree(t->right,left,current_right,s,ans);
        }
    }
    void deleteTree(TreeNode* parenthesis){
        //后序遍历删除树
        if(!parenthesis)return;
        deleteTree(parenthesis->left);
        deleteTree(parenthesis->right);
        delete parenthesis;
        parenthesis= nullptr;return;
    }
};

//21 下一个排列
void nextPermutation(vector<int>& nums) {
    //双指针 left指向最后一位right指向前一位
    //从后往前找一个相邻顺序对,left为较小的那个数
    //找到后开始从后往前找一个大于left的数，此时这个数为要与left交换的数
    //交换后，将left后面的数顺序排列（且可以证明后面的数原本为逆序排列，可以直接双指针交换)
    if(nums.size()<=1)return;//size小于=1，不做处理
    vector<int>::iterator right=nums.end()-1;
    vector<int>::iterator left=right-1;//right的左边
    while(1)
    {
            if(*left<*right)
            {
                //此时*left为较小数
                //再从后往前找一个较大数
                right=nums.end()-1;
                while(right>left)
                {
                    if(*right>*left){swap(*left,*right);break;}
                    right--;
                }
                //再将交换后的数升序排列
                sort(left+1,nums.end());//end不是最后一个元素为什么sort不需要-1？sort区间是前闭后开
                return;
            }
            if(left==nums.begin())break;
            left--;
            right--;
    }
    //left=0
    //逆置整个数组
    //双指针，首尾交换
    left=nums.begin();
    right=nums.end()-1;
    while(left<=right)
    {
        //交换两个数
        swap(*left,*right);
        left++;
        right--;
    }
    return;
}
    int main()
{
    /*
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
    */


    vector<int> a(3,0);
    a[0]=2;a[1]=3;a[2]=1;
    nextPermutation(a);
    return 0;
}