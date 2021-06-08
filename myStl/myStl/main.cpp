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

//比较元素排序，只用头指针
int split(vector<int>& nums,int left,int right)
{
	int j = left;//第一个元素做比较元素
	for (int i = left+1; i <= right; i++)
	{
		//比计较元素小的交换（因为比较元素是第一个，所以比比较元素大的一定在右侧，不用交换）
		if (nums[i] < nums[left])
		{
			j++;//记录需要交换的位置，注意不是和比较元素的位置交换，而是交换到比较元素的后一个位置，，
			swap(nums, i, j);
		}
		
	}
	//最后把比较元素交换到中间位置
	swap(nums, j, left);

	return j;

}


//比较元素排序，头尾指针，
int partion(vector<int>& nums, int left, int right)
{
	int x = nums[left];//第一个元素做比较元素
	int i = left, j = right;
	while (i < j)
	{
		//从右边开始，找到小于比较元素的数，
		while (i < j && nums[j] >= x)
		{
			j--;
		}
		//从左边开始，找到大于比较元素的数，
		while (i < j && nums[i] <= x)
		{
			i++;
		}
		//以上i,j顺序不能换，否则i会走过头，，后面交换比较元素会有问题

		if (i < j)
		{
			swap(nums, i, j);
		}
	}

	//交换比较元素
	swap(nums, i, left);

	return i;

}


//快速排序 1 只用头指针检索
void quickSort(vector<int>& nums, int left, int right)
{
	if(left < right)
	{
		//找比较元素，并根据比较元素排序，小于比较元素在左边，大于比较元素在右边
		//int x = split(nums, left, right);
		//方法2
		int x = partion(nums, left, right);
		//比较元素的左边排序，递归
		quickSort(nums, left, x - 1);
		//比较元素的右边排序，递归
		quickSort(nums, x + 1, right);
	}
}


int main()
{

	vector<int> nums = { 5, 7, 1, 6, 4, 8, 3, 2 };

	quickSort(nums, 0, nums.size()-1);
	vector<int> nums2 = {1};
	int target = 2;
	//cout << result << endl;

	system("pause");
	return 0;
}