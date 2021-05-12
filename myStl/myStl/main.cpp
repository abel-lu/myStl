#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;

//给你一个长度为 n 的整数数组，请你判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。
//
//我们是这样定义一个非递减数列的： 对于数组中任意的 i(0 <= i <= n - 2)，总满足 nums[i] <= nums[i + 1]。


//输入: nums = [4, 2, 3]
//	输出 : true
//	解释 : 你可以通过把第一个4变成1来使得它成为一个非递减数列。


class Solution {
public:
	//方法一，遍历一遍，去掉扰乱数组的元素，再遍历一次剩下的数组
	/*bool checkPossibility(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) return true;
		vector<int> v1,v2;
		int num = -1;
		v2.push_back(nums[0]);
		for (int i = 1; i < size; i++)
		{
			if (nums[i] < nums[i-1])
			{
				num++;
			}
			else
			{
				v1.push_back(nums[i - 1]);
				v2.push_back(nums[i]);
			}
		}
		if (num > 0) return false;
		v1.push_back(nums[size - 1]); 
		bool a=true,b=true;
		for (int i = 1; i < v1.size(); i++)
		{
			if (v1[i] < v1[i - 1])
				a = false;
			if (v2[i] < v2[i - 1])
				b = false;
		}
		return a || b;
	}*/

	//方法2，遍历一次，
	bool checkPossibility(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) return true;
		int num = -1;
		for (int i = 1; i < size; i++)
		{
			if (nums[i] < nums[i - 1])
			{
				num++;
				
				if(i>1&&(nums[i] < nums[i - 2]))
				{
					nums[i] = nums[i - 1];
				}
				/*else
				{
					nums[i - 1] = nums[i];
				}*/
			}
		}	
		return num<1;
	}
};

int main()
{
	vector<int> nums = { 4,2,3 };
	bool sortPeo;
	Solution solu;
	sortPeo=solu.checkPossibility(nums);
	cout << sortPeo<<endl;
	system("pause");
	return 0;

}