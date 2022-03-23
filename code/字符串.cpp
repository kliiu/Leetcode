//
// Created by 李子 on 2022/1/23.
//

#include <iostream>
#include <unordered_map>
using namespace std;


int firstUniqChar(string s) {
    unordered_map<char,int> cnt;//存储每个字符出现的次数
    for(int i=s.size()-1;i>=0;i--)
    {//倒着扫描，使最后出现的元素在map中最前面
        if(cnt.find(s[i])!=cnt.end())
            cnt[s[i]]++;
        else
            cnt[s[i]]=1;

    }
    for(auto it:cnt)
    {//从最前面开始遍历，若有等于1的元素则返回该元素位置。
        if(it.second==1)return s.find(it.first);
    }
    return -1;//若无出现次数为1的元素则返回-1；

}
int firstUniqChar_o(string s) {
    unordered_map<char,int> cnt;//存储每个字符出现的次数
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
    //先遍历magazine对元素计数

    for(auto c:magazine)
    {
        cnt[c]++;
    }
    //再遍历ransom note，不满足条件则返回false
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
        s_cnt[c]++;//count s的字符数
    }
    for(auto c:t)
    {
        t_cnt[c]++;//t的
    }
    if(s_cnt.size()!=t_cnt.size())return false;//如果字符种类不同直接false
    for(auto it:s_cnt){
    //若有s中字符数与t中不等则false；
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