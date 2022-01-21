#include <iostream>
#include <vector>
#include<algorithm>  
using namespace std;
//2022.1.18 ����

//1.����֮�� �����ⷨ
vector<int> twoSum(vector<int> &nums, int target) {
	vector<int> ans;
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		int key = target - nums[i];
		for (int j = 0; j < size; j++)
		{
			if (i == j)break;
			if (nums[j] == key)
			{
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}
	
	return ans;
}

//26.ɾ�����������е��ظ���
//ÿ��ѭ��������ÿһ��Ԫ�ض��ƶ��ı����ⷨ����ɳ�ʱ
int removeDuplicates(vector<int>& nums) {
	int size = nums.size();
	int ans = size;//�洢�޸ĺ�������С
	int j = 0;
	for (int i = 0; i < ans; i++)
	{
		j = j+ 1;//ָʾ��ǰԪ�ص���һ��
		while( j<size && nums[i] == nums[j])
		{//����ǰԪ������һԪ�����
			j++;//������һԪ��
			ans--;//�����С��1
		}
		if(j<size)//����һԪ�������鷶Χ֮��
		nums[i + 1] = nums[j];//������һԪ��

	}
	return ans;
}
//27.�Ƴ�Ԫ��
int removeElement(vector<int>& nums, int val) {
	int size = nums.size();
	int ans = size;//�洢�޸ĺ�������С
	int j = -1;
	for (int i = 0; i < ans; i++)
	{
		j = j + 1;//ָʾ��ǰԪ�ص���һ��
		while (j < size && nums[j] == val)
		{//����ǰԪ�ص���val
			j++;//ָ����һԪ��
			ans--;//�����С��1
		}
		if (j < size)//����һԪ�������鷶Χ֮��
			nums[i] = nums[j];//������һԪ��

	}
	return ans;
}
//28.��������λ��
/*
����һ�����������һ��Ŀ��ֵ��
���������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
*/

int searchInsert(vector<int>& nums, int target) {
	//���֣�
	int size = nums.size();
	int pos = 0;
	int start = 0;
	int end = size;
	int mid = 0;
	while (1) {
		mid = (start + end) / 2;
		if (nums[mid] == target)
			return mid;
		if (end - start == 1)
		{
			if (nums[start] < target)
				return end;
			else 
				return start;
		}
		else if(nums[mid]>target)
		{
			end = mid-1;//������ѭ��
		}
		else if (nums[mid] < target)
		{
			start = mid+1;//������ѭ��
		}
	
	
	}
}

//217.�����ظ�Ԫ��
//����һ���������� nums �������һֵ�������г��� �������� ������ true �����������ÿ��Ԫ�ػ�����ͬ������ false ��
//�����ⷨ��ʱ
bool containsDuplicate_TLE(vector<int>& nums) {
	for (auto it = nums.begin(); it != nums.end() - 1; it++)
		for (auto it2 = it + 1; it2 != nums.end(); it2++)
		{
			if (*it2 == *it)return true;
		}
	return false;
}
//����
//���ν����Ž�һ�����飬��һ�������ֱȽ�Ѱ�Ҳ���λ�á�
	bool containsDuplicate_(vector<int>&nums)
	{
		vector<int> now;
		if (nums.size() <= 1)return false;//ֻ��һ��Ԫ�ط���false
		now.push_back(nums[0]);//�ӵڶ�����ʼ�Ƚ�
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{//��ÿһ��Ԫ�ؽ��ж��ֱȽϣ�����ͬ�򷵻�True,�������
			;
		}
	}

// �ٷ��ⷨ��sort(nums.begin(),nums.end())��Ȼ��Ƚ�����Ԫ��
bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (auto it = nums.begin(); it != nums.end() - 1; it++)
	{
		if (*it == *(it + 1))return true;
	}

	return false;
}
//53. ����������
int maxSubArray(vector<int>& nums) {
	int pre = 0, maxAns = nums[0];
	for (const auto& x : nums) {
		pre = max(pre + x, x);
		maxAns = max(maxAns, pre);
	}
	return maxAns;
}
//88�ϲ�������������
//��һ�뷨 ����?ÿ�β�����Ҫ�ƶ�����λ�ú�����Ԫ��
void move_keys(int j, int pos,vector<int>&nums1)
{
	//�Ƚ���������Ԫ���ƶ�
	while ( j > pos)
	{
		nums1[j] = nums1[j - 1];
		j--;
	}
	
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	for (int i = 0; i < n; i++)
	{//mΪ��
		if (m == 0 && i == 0) { nums1[0] = nums2[0]; continue; }
		int now = nums2[i];
		int low = 0; int high = m+i-1;//���鳤�ȸ���
		int mid = 0;
		//������ֵС����Сֵ��������ֵ
		if (now > nums1[m + i - 1])
		{
			int pos = m + i;//���뵽���
			int j = m + i;//��ʶ��ǰҪ�ƶ���λ�ã�
			if (pos < m + i)move_keys(j,pos,nums1);
			nums1[pos] = now; continue;
		}
		if (now < nums1[0])
		{
			int pos = 0;//���뵽��ͷ
			int j = m + i;//��ʶ��ǰҪ�ƶ���λ�ã�
			if (pos < m + i)move_keys(j, pos, nums1);
			nums1[pos] = now;continue;
		}

		//���ֱȽϲ���
		while (1)
		{
			mid= (low + high) / 2;
			if (nums1[mid] == now)
			{//����ͬԪ�أ�������ͬԪ�ص���һλ
				int pos = mid + 1;
				int j = m + i;//��ʶ��ǰҪ�ƶ���λ�ã�
				if (pos < m + i)move_keys(j, pos, nums1);
				//����
				nums1[pos] = now;
				break;
			}
			
			if (high - low <= 1)
			{
				int pos = 0;
				if (now>= nums1[high])pos = high + 1;//������Ԫ�ش��ڻ����high����뵽high+1
				else pos= now >=nums1[low] ? low + 1 : low;//������Ԫ��С��high,���ڵ���low���뵽low+1����С��low���뵽low
				int j = m + i;//��ʶ��ǰҪ�ƶ���λ�ã�
				if (pos < m + i)move_keys(j, pos, nums1);
				//����
				nums1[pos] = now;
				break;
			}
			if (now > nums1[mid])
			{
				low = mid + 1;

			}
			if (now < nums1[mid])
			{
				high = mid - 1;
			}

		}
	}
		

}

int main()
{

	vector<int> nums1 = { 4,5,6,0,0,0};
	vector<int> nums2 = { 1,2,3};
	merge(nums1,3,nums2,3);
	return 0;
}