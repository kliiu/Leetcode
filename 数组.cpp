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

//��������Ľ���
//����������������nums1 �� nums2 ��������������ʽ����������Ľ��������ؽ����ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������ж����ֵĴ���һ�£�������ִ�����һ�£�����ȡ��Сֵ�������Բ�������������˳��
//����ѭ��
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
//121������Ʊ�����ʱ��
//TLE
int maxProfit_TLE(vector<int>& prices) {
    int ans=0;//max profit
    for(auto it1=prices.begin();it1!=prices.end()-1;++it1)//���һ�첻�������޷������һ�����벢����
        for(auto it2=it1+1;it2!=prices.end();++it2)
        {
            if(*it2-*it1 > ans)ans=*it2 - *it1;//����ʱ�������������ans�������ans��

        }
    return ans;
}
//AC
int maxProfit(vector<int>& prices) {
  int min_buy=*prices.begin();//��С����
  int max_profit=0;//�������
  for(auto it=prices.begin()+1;it!=prices.end();++it)//
  {//ɨ��ÿһ��Ԫ�أ���¼�����ָ�����С�����������󣬵��������ʱ�����������
      if(*it<min_buy)min_buy=*it;//������С����
      if(*it-min_buy>max_profit&&*it-min_buy>0)max_profit=*it-min_buy;//�����������
  }
  return max_profit;
}
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

    vector<vector<int>> ans;
    //���ж��Ƿ����
    if(mat.size()*mat[0].size()!=r*c)
        return mat;//�������򷵻�ԭ����
    //��reshape
    //������Ԫ�ط���չƽ�ٷ���
    //չƽ
    vector<int> all;
    for(int i=0;i<mat.size();i++)
    {
        for(auto it=mat[i].begin();it!=mat[i].end();++it)
            all.push_back(*it);
    }
    //��������������������������
    int cnt=0;//�������Ԫ��
    for(int i=0;i<r;i++){
        vector<int> temp;//���ÿһ��Ԫ��
        for(int j=0;j<c;j++){
            //push
            temp.push_back(all[cnt]);
            cnt++;
        }
        //����ɵ�һ�м���ans
        ans.push_back(temp);
    }

    return ans;

}
//118. �������
//������
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    if(numRows==1)return ans;
    for(int i=1;i<numRows;i++)
    {
        vector<int> temp;
        temp.push_back(1);//��ͷ��1
        for(int j=1;j<i;j++)
            temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
        temp.push_back(1);//����1
        ans.push_back(temp);
    }
    return ans;
}
//36 ��Ч������
bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> row_flag(10,0);//һ�б�־ÿ��������һ�γ��ֵ�λ��9*1
    vector<int> col_flag(10,0);//һ�б�־ÿ��������һ�γ��ֵ�λ��9*1
    vector<vector<int>> group_flag(10,col_flag);//group[i][j]��ʾ��i��������j�Ƿ����
    //��һ��һ�����ν���ɨ�裬ͬʱ����ÿ�������ڵ�����
    for(int i = 0;i<9;i++){
        for(int j =0;j<9;j++){
            if(board[i][j]!='.'){
                if(row_flag[board[i][j]-'0']==1||group_flag[i/3*3+j/3][board[i][j]-'0']==1){return false;//���ѱ���򷵻�false��������
                }
                else{
                    row_flag[board[i][j]-'0']=1;//��ɨ��,�����
                    //(x/3)*3+y/3Ϊ��x��y)���ڵ�3*3�����
                    //��4,5)��3+1=4����4����0��ʼ��ţ�
                    group_flag[i/3*3+j/3][board[i][j]-'0']=1;//����
                    //board[i][j]-'0'���ַ�charתΪint��'0'=48

                }
            }
            if(board[j][i]!='.'){if(col_flag[board[j][i]-'0']==1)return false;
                else col_flag[board[j][i]-'0']=1;//��ɨ�轫�����ֱ�Ǳ�Ϊ1
            }
        }
        //������λ����0
        fill(row_flag.begin(),row_flag.end(),0);
        fill(col_flag.begin(),col_flag.end(),0);
    }
    return true;
}


//73������0
void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows;
    set<int> cols;
    for(int i=0;i<matrix.size();i++)
        for(int j=0; j<matrix[i].size();j++)
        {
            if(matrix[i][j]==0)//������0�����������о���0
            {
                //����������
                rows.emplace(i);//��insert����
                cols.emplace(j);
            }


        }
    //��ʼ��0
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
