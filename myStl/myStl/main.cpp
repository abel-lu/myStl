#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

//
//给定一个包含红色、白色和蓝色，一共 n 个元素的数组
//原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

//输入：nums = [2, 0, 2, 1, 1, 0]
//输出：[0, 0, 1, 1, 2, 2]

class solution
{
public:

	//方法1暴力
	void sortColors(vector<int>& nums) {
		int size = nums.size(); 
		if (size < 2) return;
		int count[3] = {0};
		for (auto x : nums)
		{
			if (x == 0)
			{
				count[0]++;
			}
			else if (x == 1)
			{
				count[1]++;
			}
			else
			{
				count[2]++;
			}
		}
		vector<int> res;
		int i = 0;
		while (i<3)
		{
			while (count[i]--)
			{
				res.push_back(i);
			}
			i++;
		}
		nums = res;
		return;
	}
};

int main()
{
	solution solu;

	vector<int> nums = { 2,0,2,1,1,0 };
	string str = "eeeee";
	int target = 0;
	solu.sortColors(nums);
	//cout << result << endl;

	system("pause");
	return 0;
}