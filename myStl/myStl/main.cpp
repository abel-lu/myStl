#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;


//已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0, 1, 4, 4, 5, 6, 7] 在变化后可能得到：
//若旋转 4 次，则可以得到[4, 5, 6, 7, 0, 1, 4]
//若旋转 7 次，则可以得到[0, 1, 4, 4, 5, 6, 7]
//注意，数组[a[0], a[1], a[2], ..., a[n - 1]] 旋转一次 的结果为数组[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] 。
//
//给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

//输入：nums = [1, 3, 5]
//输出：1

class solution
{
public:

	//方法1暴力


	//方法2，二分
	//先找旋转数组的特点，只有4种可能，
	/* 1 -------

				---
			--	   
	   2 --

	   3 --		---
			---

	   4	---
	     --
						--
					---
				---
	*/
	int findMin(vector<int>& nums) {
		int n = nums.size();
		if (n ==1) return nums[0];
		int left=0, right=n-1;
		int min = nums[0];
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < min)
			{
				right = mid - 1;
				min = nums[mid];
			}
			else
			{
				if (nums[left] < nums[right])
				{
					right = mid - 1;
				}
				else if (nums[left] > nums[right])
				{
					left = mid + 1;
				}
				else
				{
					right--;
					left++;
				}
			}
			
		}
		return min;

	}
};

int main()
{
	solution solu;

	vector<int> nums = { 1,2,1 };
	int target = 0;
	int result = solu.findMin(nums);
	//cout << result << endl;

	system("pause");
	return 0;
}