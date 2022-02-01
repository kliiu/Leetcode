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


int main()
{
    vector<int> nums1={-10,-10,-9,-4,1,9,9};
    vector<int> nums2={-5,-3,0,7,8,8};
    ListNode* list1= creatList(nums1);
    ListNode* list2= creatList(nums2);
    ListNode* ans=mergeTwoLists(list1,list2);

    return 0;
}