# 653. ����֮�� IV - ���� BST
## ��Ŀ����
https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/

## ˼·
22.03.08û�뵽��Ч��˼·�����˱�����Ȼ�������ԡ�

�ٷ���⣺ά��һ��hashset,����ÿ����㡣��k-��ǰ����ֵ������set,˵��
�����ҵ������򽫴˽�����hashset�������˽������Һ��ӡ�
## ����
### C++ Code:
```cpp
//���Լ��Ľ�
bool midorder(TreeNode* root, int k,unordered_set<int,int> visited )
{
    if(!root)return false;//��Ϊ��������ֱ�ӷ���
    if(visited.find(k-root->val)!=visited.end())//�ҵ�set�д���k-val����ʾ������
        return true;
    visited.emplace(root->val);//�������в����ڣ��򽫵�ǰ�����뼯��
    //�������
    return midorder(root->left,k,visited)|| midorder(root->right,k,visited);
}
bool findTarget(TreeNode* root, int k) {

    unordered_set<int,int>visited;//�ѱ����ļ���
    return midorder(root,k,visited);

}
```
