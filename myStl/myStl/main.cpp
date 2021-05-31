#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;


//给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

//输入: [1, 1, 2, 3, 3, 4, 4, 8, 8]
//	输出 : 2

class solution
{
public:

	int singleNonDuplicate(vector<int>& nums) {
		//暴力法
		/*int n = nums.size();
		if (n == 1) return nums[0];
		if (nums[0] != nums[1]) return nums[0];
		for (int i = 2; i < n-2; i+2)
		{
			if (nums[i] != nums[i + 1])
			{
				return nums[i];
			}
		}
		return nums[n-1];*/

		//二分法
		int n = nums.size();
		int left = 0,right = n - 1,mid;
		while (left < right)
		{
			mid = left+(right-left) / 2;
			if (mid % 2 == 1) mid--;
			if (nums[mid] == nums[mid + 1])
			{
				left = mid+2;
			}
			else
			{
				right = mid;
				
			}
		}
		return nums[left];
	}
};

int main()
{
	solution solu;

	vector<int> nums = { 1,1,2,3,3,4,4,8,8};
	int target = 0;
	int result = solu.singleNonDuplicate(nums);
	//cout << result << endl;

	system("pause");
	return 0;
}