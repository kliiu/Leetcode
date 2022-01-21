#include <iostream>
#include <vector>
#include<algorithm>  
using namespace std;
//2022.1.18 数组

//1.两数之和 暴力解法
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

//26.删除有序数组中的重复项
//每次循环将后面每一个元素都移动的暴力解法会造成超时
int removeDuplicates(vector<int>& nums) {
	int size = nums.size();
	int ans = size;//存储修改后的数组大小
	int j = 0;
	for (int i = 0; i < ans; i++)
	{
		j = j+ 1;//指示当前元素的下一个
		while( j<size && nums[i] == nums[j])
		{//若当前元素与下一元素相等
			j++;//更新下一元素
			ans--;//数组大小减1
		}
		if(j<size)//当下一元素在数组范围之内
		nums[i + 1] = nums[j];//更新下一元素

	}
	return ans;
}
//27.移除元素
int removeElement(vector<int>& nums, int val) {
	int size = nums.size();
	int ans = size;//存储修改后的数组大小
	int j = -1;
	for (int i = 0; i < ans; i++)
	{
		j = j + 1;//指示当前元素的下一个
		while (j < size && nums[j] == val)
		{//若当前元素等于val
			j++;//指向下一元素
			ans--;//数组大小减1
		}
		if (j < size)//当下一元素在数组范围之内
			nums[i] = nums[j];//更新下一元素

	}
	return ans;
}
//28.搜索插入位置
/*
给定一个排序数组和一个目标值，
在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
*/

int searchInsert(vector<int>& nums, int target) {
	//二分？
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
			end = mid-1;//避免死循环
		}
		else if (nums[mid] < target)
		{
			start = mid+1;//避免死循环
		}
	
	
	}
}

//217.存在重复元素
//给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
//暴力解法超时
bool containsDuplicate_TLE(vector<int>& nums) {
	for (auto it = nums.begin(); it != nums.end() - 1; it++)
		for (auto it2 = it + 1; it2 != nums.end(); it2++)
		{
			if (*it2 == *it)return true;
		}
	return false;
}
//放弃
//依次将数放进一个数组，下一个数二分比较寻找插入位置。
	bool containsDuplicate_(vector<int>&nums)
	{
		vector<int> now;
		if (nums.size() <= 1)return false;//只有一个元素返回false
		now.push_back(nums[0]);//从第二个开始比较
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{//对每一个元素进行二分比较，有相同则返回True,无则插入
			;
		}
	}

// 官方解法：sort(nums.begin(),nums.end())，然后比较相邻元素
bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (auto it = nums.begin(); it != nums.end() - 1; it++)
	{
		if (*it == *(it + 1))return true;
	}

	return false;
}
//53. 最大子数组和
int maxSubArray(vector<int>& nums) {
	int pre = 0, maxAns = nums[0];
	for (const auto& x : nums) {
		pre = max(pre + x, x);
		maxAns = max(maxAns, pre);
	}
	return maxAns;
}
//88合并两个有序数组
//第一想法 二分?每次插入需要移动插入位置后所有元素
void move_keys(int j, int pos,vector<int>&nums1)
{
	//先将后面所有元素移动
	while ( j > pos)
	{
		nums1[j] = nums1[j - 1];
		j--;
	}
	
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	for (int i = 0; i < n; i++)
	{//m为空
		if (m == 0 && i == 0) { nums1[0] = nums2[0]; continue; }
		int now = nums2[i];
		int low = 0; int high = m+i-1;//数组长度更新
		int mid = 0;
		//若插入值小于最小值或大于最大值
		if (now > nums1[m + i - 1])
		{
			int pos = m + i;//插入到最后
			int j = m + i;//标识当前要移动的位置；
			if (pos < m + i)move_keys(j,pos,nums1);
			nums1[pos] = now; continue;
		}
		if (now < nums1[0])
		{
			int pos = 0;//插入到开头
			int j = m + i;//标识当前要移动的位置；
			if (pos < m + i)move_keys(j, pos, nums1);
			nums1[pos] = now;continue;
		}

		//二分比较插入
		while (1)
		{
			mid= (low + high) / 2;
			if (nums1[mid] == now)
			{//有相同元素，插入相同元素的下一位
				int pos = mid + 1;
				int j = m + i;//标识当前要移动的位置；
				if (pos < m + i)move_keys(j, pos, nums1);
				//插入
				nums1[pos] = now;
				break;
			}
			
			if (high - low <= 1)
			{
				int pos = 0;
				if (now>= nums1[high])pos = high + 1;//若插入元素大于或等于high则插入到high+1
				else pos= now >=nums1[low] ? low + 1 : low;//若插入元素小于high,大于等于low插入到low+1，若小于low插入到low
				int j = m + i;//标识当前要移动的位置；
				if (pos < m + i)move_keys(j, pos, nums1);
				//插入
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