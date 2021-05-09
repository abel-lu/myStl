#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;

//假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
//每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//
//请你重新构造并返回输入数组 people 所表示的队列。
//返回的队列应该格式化为数组 queue ，
//其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

//输入：people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
//输出：[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]


class Solution {
public:

	static bool compare(vector<int>& a, vector<int>& b)
	{
		if (a[0]<b[0])
		{
			return false;
		}
		else if (a[0]>b[0])
		{
			return true;
		}
		else {
			if (a[1]>b[1])
			{
				return false;
			}
			else return true;
		}
	}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		
		//先按右区间升序排序，如果相等，按左区间升序
		int size = people.size();
		if (size < 2) return people;
		sort(people.begin(),people.end(), compare);
		vector<vector<int>> s;
		

		for (int i = 0; i < size; i++)
		{
			int pos = people[i][1];
			s.insert(s.begin() + pos, people[i]);
			//cout << people[i][0];
		}
		return s;

	}
};


int main()
{
	vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	vector<vector<int>> sortPeo;
	Solution solu;
	sortPeo=solu.reconstructQueue(people);
	for (int i = 0; i < sortPeo.size(); i++)
	{	
		cout << sortPeo[i][0] << sortPeo[i][1] << endl;;
	}
	system("pause");
	return 0;

}