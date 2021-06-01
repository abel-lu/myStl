#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;


//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。


//输入：nums1 = [1, 3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1, 2, 3] ，中位数 2

class solution
{
public:

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int n = (n1 + n2) / 2;
		vector<int> nums;
		for (int i = 0, j = 0;;)
		{
			if ((i > n1 - 1)&&(j < n2 ))
			{
				nums.push_back(nums2[j]);
				j++;
			}
			else if ((j > n2 - 1 )&&( i < n1 ))
			{
				nums.push_back(nums1[i]);
				i++;
			}
			else
			{

				if (nums1[i] < nums2[j])
				{
					nums.push_back(nums1[i]);
					i++;
				}
				else
				{
					nums.push_back(nums2[j]);
					j++;
				}
			}
			if (nums.size() == n+1) break;
		}
		if ((n1 + n2) % 2 == 0)
		{
			return double(nums[n] + nums[n - 1]) / 2;
		}
		return nums[n];
	}
};

int main()
{
	solution solu;

	vector<int> nums1 = { };
	vector<int> nums2 = {1};
	int target = 0;
	double result = solu.findMedianSortedArrays(nums1, nums2);
	//cout << result << endl;

	system("pause");
	return 0;
}