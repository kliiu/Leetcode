#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;
//by kliiu

class Vectors {
public:
    int firstUniqChar(string s) {

    }
};
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

//两个数组的交集
//给你两个整数数组nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
//暴力循环
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    vector<char> if_add(nums2.size(),'n');//it's single quotes 'n' not double
    //n stands for not added yet, y stands for this element had been added in ans
    for(auto it=nums1.begin();it!=nums1.end();++it)
    {
        for(int i=0;i<nums2.size();i++)
        {   if(if_add[i]=='n')
            {
                if (*it == nums2[i]) //if equal
                {
                    ans.push_back(*it);//add to ans
                    if_add[i] = 'y';//set this element in num2 'y'
                    break;
                }//if it==it2 add it to ans, each one element should only be compared once thus break
            }
        }
    }
    return ans;


}
//121买卖股票的最佳时机
//TLE
int maxProfit_TLE(vector<int>& prices) {
    int ans=0;//max profit
    for(auto it1=prices.begin();it1!=prices.end()-1;++it1)//最后一天不遍历，无法在最后一天买入并卖出
        for(auto it2=it1+1;it2!=prices.end();++it2)
        {
            if(*it2-*it1 > ans)ans=*it2 - *it1;//若此时卖出的利润大于ans，则更新ans；

        }
    return ans;
}
//AC
int maxProfit(vector<int>& prices) {
  int min_buy=*prices.begin();//最小卖出
  int max_profit=0;//最大利润
  for(auto it=prices.begin()+1;it!=prices.end();++it)//
  {//扫描每一个元素，记录并保持更新最小买入和最大利润，当利润更大时更新最大利润
      if(*it<min_buy)min_buy=*it;//更新最小买入
      if(*it-min_buy>max_profit&&*it-min_buy>0)max_profit=*it-min_buy;//更新最大利润
  }
  return max_profit;
}
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

    vector<vector<int>> ans;
    //先判断是否合理
    if(mat.size()*mat[0].size()!=r*c)
        return mat;//不符合则返回原矩阵
    //再reshape
    //将所有元素放入展平再放入
    //展平
    vector<int> all;
    for(int i=0;i<mat.size();i++)
    {
        for(auto it=mat[i].begin();it!=mat[i].end();++it)
            all.push_back(*it);
    }
    //按给定当行数和列数依次填入
    int cnt=0;//标记填入元素
    for(int i=0;i<r;i++){
        vector<int> temp;//存放每一行元素
        for(int j=0;j<c;j++){
            //push
            temp.push_back(all[cnt]);
            cnt++;
        }
        //将完成的一行加入ans
        ans.push_back(temp);
    }

    return ans;

}
//118. 杨辉三角
//暴力解
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    if(numRows==1)return ans;
    for(int i=1;i<numRows;i++)
    {
        vector<int> temp;
        temp.push_back(1);//开头的1
        for(int j=1;j<i;j++)
            temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
        temp.push_back(1);//最后的1
        ans.push_back(temp);
    }
    return ans;
}
//36 有效的数独
bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> row_flag(10,0);//一行标志每个数字上一次出现的位置9*1
    vector<int> col_flag(10,0);//一列标志每个数字上一次出现的位置9*1
    vector<vector<int>> group_flag(10,col_flag);//group[i][j]表示第i宫的数字j是否出现
    //对一行一列依次进行扫描，同时更新每个数所在的组数
    for(int i = 0;i<9;i++){
        for(int j =0;j<9;j++){
            if(board[i][j]!='.'){
                if(row_flag[board[i][j]-'0']==1||group_flag[i/3*3+j/3][board[i][j]-'0']==1){return false;//若已标记则返回false，不满足
                }
                else{
                    row_flag[board[i][j]-'0']=1;//行扫描,并标记
                    //(x/3)*3+y/3为（x，y)所在的3*3宫编号
                    //（4,5)在3+1=4，第4宫（0开始编号）
                    group_flag[i/3*3+j/3][board[i][j]-'0']=1;//组标记
                    //board[i][j]-'0'将字符char转为int，'0'=48

                }
            }
            if(board[j][i]!='.'){if(col_flag[board[j][i]-'0']==1)return false;
                else col_flag[board[j][i]-'0']=1;//列扫描将该数字标记变为1
            }
        }
        //将行列位置置0
        fill(row_flag.begin(),row_flag.end(),0);
        fill(col_flag.begin(),col_flag.end(),0);
    }
    return true;
}


//73矩阵置0
void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows;
    set<int> cols;
    for(int i=0;i<matrix.size();i++)
        for(int j=0; j<matrix[i].size();j++)
        {
            if(matrix[i][j]==0)//若等于0则将其所在行列均置0
            {
                //保存行列数
                rows.emplace(i);//比insert更快
                cols.emplace(j);
            }


        }
    //开始置0
    for(int i=0;i<matrix.size();i++)
        for(int j=0; j<matrix[i].size();j++)
        {
            if(rows.find(i)!=rows.end()||cols.find(j)!=cols.end())
                matrix[i][j]=0;
        }

}

int main() {
    vector<int> nums1 = {0, 1, 5, 3, 6, 4};
    vector<vector<int>>mat={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(mat);
    //bool a= isValidSudoku(mat);
    return 0;
}
