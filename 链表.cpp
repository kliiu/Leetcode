//
// Created by 李子 on 2022/1/27.
//链表部分代码

#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

//141 环形链表
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;
    ListNode *temp=head;
    while(temp)
    {
        if(visited.find(temp)!=visited.end())return true;
        //add to visited
        visited.insert(temp);
        temp=temp->next;
    }

    return false;
}
//21合并两个链表
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //特殊情况
    if(!list1)return list2;
    else if(!list2) return list1;
    ListNode*temp1,*temp2;
    if(list1->val<=list2->val){
        temp1=list1;//point to list1
        temp2=list2;//point to list2
    }
    else{
        temp1=list2;//point to list1
        temp2=list1;
    }
    ListNode* last=NULL;
    ListNode* ans=temp1;
    while(temp2)//当temp2不为空，进入循环
    {   //依次比较temp2 val与temp1 val,把temp2中的元素插入到temp1

        while(temp1){
            //若temp2<=temp1插入到temp1 val之前
            if(temp2->val<temp1->val){
                ListNode* insert=new ListNode(temp2->val,temp1);
                last->next=insert;
                last=last->next;
                break;//插入后，切换到下一元素
            }
            else{if(!temp1->next)//若下一个节点为空，直接插入此节点及后面全部节点到末尾
                    {temp1->next=temp2;
                        return ans;}
            last=temp1;
            temp1=temp1->next;}
        }
        temp2=temp2->next;
    }
    return ans;
}

ListNode *creatList(vector<int> num)
{   if(num.empty())return NULL;
    ListNode* list=new ListNode(num[0]);
    ListNode* temp=list;
    for(int i=0;i<num.size();i++)
    {
        if(i==0)continue;
        ListNode *newnode=new ListNode(num[i]);
        temp->next=newnode;
        temp=temp->next;
    };
    return  list;
}
ListNode *creatList_head(vector<int> nums){

    ListNode* head=new ListNode();
    ListNode* p=head;
    for(auto i:nums)
    {
        ListNode* temp=new ListNode(i);
        p->next=temp;
        p=p->next;
    }
    return head;
}
//203移除链表元素
ListNode* removeElements(ListNode* head, int val) {
    ListNode* newhead=new ListNode();
    newhead->next=head;
    ListNode* p=head;
    ListNode* pre=newhead;//pre.next=p
    while(p){
        //if p.val==val, delete this element
        if(p->val==val) pre->next=p->next;
        else pre=pre->next;
        p=p->next;
    }
    return newhead->next;
}
//206反转链表
ListNode* reverseList(ListNode* head) {
    ListNode* p=head;//当前节点
    ListNode* pre=NULL;//存储前一个
    ListNode* next=head;//存储后一个
    while(p) {
        //先更新后一个
        next=next->next;
        //使当前节点指向前一个节点
        p->next=pre;
        //更新前驱节点为当前节点
        pre=p;
        //更新当前节点
        p=next;
    }
    return pre;//链表为空则返回空指针；
}
//83删除排序链表中的重复元素
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* pre=head;
    ListNode* p=pre;
    while(p)
    {   //若当前节点为头节点，直接下一个
        if(p==head){p=p->next;continue;}
        //若当前值等于前驱节点则使前驱节点next指向当前节点的下一个，则删除了当前节点。
        if(p->val==pre->val){pre->next=p->next;}
        //否则使前驱节点更新为当前节点
        else pre=p;
        //更新当前节点
        p=p->next;
    }
    return head;
}
/*
int main()
{
    vector<int> nums1={-10,-10,-9,-4,1,9,9};
    vector<int> nums2={};
    ListNode* list1= creatList(nums1);
    ListNode* list2= creatList(nums2);
    ListNode* ans=deleteDuplicates(list1);

    return 0;
}
*/