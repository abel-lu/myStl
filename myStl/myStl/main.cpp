#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;


//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。


//输入: [3, 2, 1, 5, 6, 4] 和 k = 2
//	输出 : 5

class solution
{
public:
	void swap(vector<int>& nums, int l, int r)
	{
		int temp = nums[l];
		nums[l] = nums[r];
		nums[r] = temp;
	}

	int qsort(vector<int>& nums, int left, int right)
	{
		int l = left, r = right;	
		int compare = nums[left];
		while (l < r)
		{
			while (nums[r]<=compare && l<r)
			{
				r--;
			}
			while (nums[l]>=compare && l<r)
			{
				l++;
			}
			if (l < r)
			{
				swap(nums, l, r);
			}
		}
		swap(nums, left, l);
		return l;
	}

	void quicksort(vector<int>& nums, int left,int right)
	{
		while (left < right)
		{
			int mid = qsort(nums, left, right);
			quicksort(nums, left, mid-1);
			quicksort(nums, mid + 1, right);
		}
	}

	int findKthLargest(vector<int>& nums, int k) {
		//1.调用函数
		//sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
		//return nums[k-1];

		//1.找到第k个数，只需要排到k,后面不需要排序
		int left = 0, right = nums.size();
		quicksort(nums, left, right-1);

		return 0;
	}
};

int main()
{
	solution solu;

	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
	vector<int> nums2 = {1};
	int target = 2;
	int result = solu.findKthLargest(nums,target);
	//cout << result << endl;

	system("pause");
	return 0;
}