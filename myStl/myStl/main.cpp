#include<iostream>
#include<vector>
#include<unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;
//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段
//同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

//输入：S = "ababcbacadefegdehijhklij"
//输出：[9, 7, 8]
//解释：
//划分结果为 "ababcbaca", "defegde", "hijhklij"。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

vector<int> cutstring(string s)
{
	if (s.empty()) return vector<int>(0);
	vector<int> cutvec;
	unordered_map<char, int> map;
	int size = s.size();
	//用哈希map记录每个字符出现的最后位置
	for (int i = 0; i<size; i++)
	{
		map[s[i]] = i;
	}
	//map的key个数
	//int s_count = map.size();
	int loc= map[s[0]],pos=0,j=0;//划分字符串的位置
	//cutvec.push_back(loc);//记录第一个划分位置
	while(1)
	{
		for (j = pos; j < loc; j++)
		{
			if (map[s[j]] > loc)
			{
				//更新当前字符段的最远位置
				loc = map[s[j]];
			}
		}
		j++;
		cutvec.push_back(loc-pos);
		pos = loc;
		loc = map[s[j]];
		if (j == size) break;
	}
	cutvec[0]++;
	return cutvec;
}

int main()
{
	vector<int> cutNum;
	string S = "ababcbacadefegdehijhklij";
	cutNum = cutstring(S);
	int i = 0;
	system("pause");
	return 0;

}