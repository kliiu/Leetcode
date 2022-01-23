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



int main()
{
    string a="loveleetcode";
    int ans=firstUniqChar_o(a);
    return 0;
}