//
// Created by ���� on 2022/1/23.
//

#include <iostream>
#include <unordered_map>
using namespace std;


int firstUniqChar(string s) {
    unordered_map<char,int> cnt;//�洢ÿ���ַ����ֵĴ���
    for(int i=s.size()-1;i>=0;i--)
    {//����ɨ�裬ʹ�����ֵ�Ԫ����map����ǰ��
        if(cnt.find(s[i])!=cnt.end())
            cnt[s[i]]++;
        else
            cnt[s[i]]=1;

    }
    for(auto it:cnt)
    {//����ǰ�濪ʼ���������е���1��Ԫ���򷵻ظ�Ԫ��λ�á�
        if(it.second==1)return s.find(it.first);
    }
    return -1;//���޳��ִ���Ϊ1��Ԫ���򷵻�-1��

}
int firstUniqChar_o(string s) {
    unordered_map<char,int> cnt;//�洢ÿ���ַ����ֵĴ���
    for(int i=s.size()-1;i>=0;i--)
    {
        cnt[s[i]]++;

    }
    for (int i = 0; i < s.size(); ++i) {
        if (cnt[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int> cnt;
    //�ȱ���magazine��Ԫ�ؼ���

    for(auto c:magazine)
    {
        cnt[c]++;
    }
    //�ٱ���ransom note�������������򷵻�false
    for(auto c:ransomNote)
    {
        if(cnt[c]==0)return false;
        else cnt[c]--;
    }
    return true;
}
bool isAnagram(string s, string t) {
    unordered_map<char,int> s_cnt;
    unordered_map<char,int> t_cnt;

    for(auto c:s)
    {
        s_cnt[c]++;//count s���ַ���
    }
    for(auto c:t)
    {
        t_cnt[c]++;//t��
    }
    if(s_cnt.size()!=t_cnt.size())return false;//����ַ����಻ֱͬ��false
    for(auto it:s_cnt){
    //����s���ַ�����t�в�����false��
        if(t_cnt[it.first]!=it.second)return false;
    }
    return true;
}
/*
int main()
{
    string s="anagram";
    string t="nagaram";
    bool ans=isAnagram(s,t);
    return 0;
}
 */