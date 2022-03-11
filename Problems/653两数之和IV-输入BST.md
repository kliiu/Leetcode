# 653. 两数之和 IV - 输入 BST
## 题目描述
https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/

## 思路
22.03.08没想到高效的思路，除了遍历树然后找数对。

官方题解：维持一个hashset,遍历每个结点。若k-当前结点的值存在于set,说明
可以找到，否则将此结点加入hashset并遍历此结点的左右孩子。
## 代码
### C++ Code:
```cpp
//非自己的解
bool midorder(TreeNode* root, int k,unordered_set<int,int> visited )
{
    if(!root)return false;//若为空树，则直接返回
    if(visited.find(k-root->val)!=visited.end())//找到set中存在k-val，表示有数对
        return true;
    visited.emplace(root->val);//若集合中不存在，则将当前结点加入集合
    //中序遍历
    return midorder(root->left,k,visited)|| midorder(root->right,k,visited);
}
bool findTarget(TreeNode* root, int k) {

    unordered_set<int,int>visited;//已遍历的集合
    return midorder(root,k,visited);

}
```
