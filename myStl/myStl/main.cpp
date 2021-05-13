#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;

//给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
//函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。
//numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。



//输入：numbers = [2, 7, 11, 15], target = 9
//输出：[1, 2]
//解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2


class Solution {
public:

	//方法一，暴力法，
	//vector<int> twoSum(vector<int>& numbers, int target) {
	//	vector<int> index(2,0);
	//	int n = numbers.size();

	//	for (int i = 0; i < n; i++)
	//	{
	//		for (int j = i+1; j < n; j++)
	//		{
	//			if (numbers[i] + numbers[j] == target)
	//			{
	//				index[0] = i;
	//				index[1] = j;
	//			}
	//			if ((numbers[i] + numbers[j]) >target)
	//			{
	//				continue;
	//				//j = i + 1;
	//			}
	//		}
	//	}
	//	return index;
	//}

	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> index(2,0);
		int n = numbers.size();

		for (int i = 0, j = n; i < n, j >-1; )
		{
			if (numbers[i] + numbers[j] == target)
			{
				index[0] = i+1;
				index[1] = j+1;
				return index;
			}
			else if ((numbers[i] + numbers[j]) > target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return vector<int>{-1,-1 };
	}

};

int main()
{
	vector<int> nums = { 1,2,3,4,4,9,56,90 };
	vector<int> sortPeo;
	Solution solu;
	sortPeo=solu.twoSum(nums,8);
	//cout << sortPeo<<endl;
	system("pause");
	return 0;

}