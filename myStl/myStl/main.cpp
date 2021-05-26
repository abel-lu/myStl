#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回 [-1, -1]。




//输入：nums = [5, 7, 7, 8, 8, 10], target = 8
//输出：[3, 4]

class solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		//方法1	，暴力
		/*int n = nums.size();
		if (n < 1)return { -1,-1 };
		int count=0,res;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == target)
			{
				count++;
				res = i;
			}
			else if(nums[i]>target)
			{
				break;
			}
		}
		if (count == 0) return{ -1,-1 };
		res = res - count + 1;
		return { res,res+count-1 };*/

		//二分查找
		int n = nums.size();
		if (n < 1)return { -1,-1 };
		int count=0,res=0;
		//定义左右区间
		int left = 0,right = n-1,mid;
		
		while(left<=right)
		{
			mid = (right+left) / 2;
			if (nums[mid] < target)
			{
				left = mid+1;
			}
			else if(nums[mid]>target)
			{
				right = mid-1;
			}
			else
			{
				count++;
				break;
			}
		}
		if (count > 0)
		{
			count = mid;
			while (count < nums.size() && nums[count] == target)
			{
				res++;
				count++;
			}
			while (mid < nums.size() && nums[mid] == target)
			{
				res++;
				mid--;
				count=mid;
			}
		}

		if (res == 0) return{ -1,-1 };
		count++;
		return { count,count+res-2 };
	}
};

int main()
{
	solution solu;

	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 6;
	vector<int> result = solu.searchRange(nums, target);
	//cout << result << endl;
	system("pause");
	return 0;

}