#include<iostream>
#include<vector>
#include <numeric>
#include <algorithm>
using namespace std;
//一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，
//若有一个气球的直径的开始和结束坐标为 xstart，xend，
//且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 
//弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

//给你一个数组 points ，其中 points[i] = [xstart, xend] ，
//返回引爆所有气球所必须射出的最小弓箭数。

//输入：points = [[10, 16], [2, 8], [1, 6], [7, 12]]
//输出：2
//解释：对于该样例，x = 6 可以射爆[2, 8], [1, 6] 两个气球，以及 x = 11 射爆另外两个气球


//思路：打气球即，找重叠区间问题，让重叠区间合成一个区间，
//将所有区间按右区间排序，依次比较区间，如果后一个区间和前一个重叠，直接移除后一个区间即可实现功能
int eraseOverlap(vector<vector<int>>& points)
{
	if (points.empty())
	{
		return 0;
	}
	int size = points.size();
	//自定义排序规则：按照数组第二个值的大小排列，在本题中即按区间结尾升序排列
	sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
		return a[1] < b[1];
	});
	int pre = points[0][1];
	int count = 0;//需要移出的区间个数
	for (int i = 1; i < size; i++)
	{

		if (points[i][0] > pre)
		{
			//区间不重叠，更新pre为当前区间的结尾
			pre = points[i][1];
		}
		else
		{
			//如果后一个区间不超过前一个区间，合并区间
			count++;
		}
	}
	return size - count;
}

int main()
{
	vector<vector<int>> points = { {10,16},{2,8},{1,6},{7,12} };
	int num=eraseOverlap(points);
	cout << "需要" << num << "个弓箭" << endl;
	system("pause");
	return 0;
	
}