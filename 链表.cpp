//
// Created by ���� on 2022/1/27.
//�����ִ���

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

//141 ��������
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
//21�ϲ���������
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //�������
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
    while(temp2)//��temp2��Ϊ�գ�����ѭ��
    {   //���αȽ�temp2 val��temp1 val,��temp2�е�Ԫ�ز��뵽temp1

        while(temp1){
            //��temp2<=temp1���뵽temp1 val֮ǰ
            if(temp2->val<temp1->val){
                ListNode* insert=new ListNode(temp2->val,temp1);
                last->next=insert;
                last=last->next;
                break;//������л�����һԪ��
            }
            else{if(!temp1->next)//����һ���ڵ�Ϊ�գ�ֱ�Ӳ���˽ڵ㼰����ȫ���ڵ㵽ĩβ
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
//203�Ƴ�����Ԫ��
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
//206��ת����
ListNode* reverseList(ListNode* head) {
    ListNode* p=head;//��ǰ�ڵ�
    ListNode* pre=NULL;//�洢ǰһ��
    ListNode* next=head;//�洢��һ��
    while(p) {
        //�ȸ��º�һ��
        next=next->next;
        //ʹ��ǰ�ڵ�ָ��ǰһ���ڵ�
        p->next=pre;
        //����ǰ���ڵ�Ϊ��ǰ�ڵ�
        pre=p;
        //���µ�ǰ�ڵ�
        p=next;
    }
    return pre;//����Ϊ���򷵻ؿ�ָ�룻
}
//83ɾ�����������е��ظ�Ԫ��
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* pre=head;
    ListNode* p=pre;
    while(p)
    {   //����ǰ�ڵ�Ϊͷ�ڵ㣬ֱ����һ��
        if(p==head){p=p->next;continue;}
        //����ǰֵ����ǰ���ڵ���ʹǰ���ڵ�nextָ��ǰ�ڵ����һ������ɾ���˵�ǰ�ڵ㡣
        if(p->val==pre->val){pre->next=p->next;}
        //����ʹǰ���ڵ����Ϊ��ǰ�ڵ�
        else pre=p;
        //���µ�ǰ�ڵ�
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