#include<iostream>
#include<vector>
#include <numeric>
#include <algorithm>
using namespace std;
//给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
//首尾相连不算重叠
//例如:输入[[1,2][2,4][1,3]]
//输出一个整数，表示需要移除的区间数量


//思路：将所有区间按右区间排序，依次比较区间，如果后一个区间和前一个重叠，直接移除后一个区间即可实现功能
int eraseOverlap(vector<vector<int>>& input)
{
	if (input.empty())
	{
		return 0;
	}
	int size = input.size();
	//自定义排序规则：按照数组第二个值的大小排列，在本题中即按区间结尾升序排列
	sort(input.begin(), input.end(), [](vector<int> a, vector<int> b) {
		return a[1] < b[1];
	});
	int pre = input[0][1];
	int count=0;//需要移出的区间个数
	for (int i = 1; i < size; i++)
	{
		//如果后一个区间超过前一个区间，直接移出后一个
		if (input[i][0] < pre )
		{
			count++;
		}
		else
		{
			//区间不重叠，更新pre为当前区间的结尾
			pre = input[i][1];
		}
	}
	return count;
}

int main()
{
	vector<vector<int>> input = { {1,2},{2,4},{1,3},{1,4} };
	int num=eraseOverlap(input);
	cout << "移除" << num << "个区间" << endl;
	system("pause");
	return 0;
	
}