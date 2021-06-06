#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

// 快速排序，两种方法

void swap(vector<int>& nums,int i,int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}


void merge(vector<int>& nums, int left, int right,int mid)
{
	for()
}


//快速排序 1 只用头指针检索
void Sort(vector<int>& nums, int left, int right)
{
	if(left < right)
	{
		int mid = (right - left) / 2;
		//分治,左右子序分别排序
		Sort(nums, left, mid);
		//比较元素的右边排序，递归
		Sort(nums, mid+1, right);
		
		//融合排序后左右子序
		merge(nums,left,right,mid);
	}
}


int main()
{

	vector<int> nums = { 5, 7, 1, 6, 4, 8, 3, 2 };

	Sort(nums, 0, nums.size()-1);
	vector<int> nums2 = {1};
	int target = 2;
	//cout << result << endl;

	system("pause");
	return 0;
}