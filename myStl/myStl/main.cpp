#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;


//给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

//输入:
//"tree"
//
//输出 :
//	"eert"

class solution
{
public:

	//方法1暴力
	string frequencySort(string& s) {
		unordered_map<char,int> map;
		int size = s.size();
		int max;
		if (size < 2) return s;
		max = 0;
		for(auto a:s)
		{
			map[a]++;
		}
		
		vector<char>* res= new vector<char>[s.length()+1];
		//vector<char> res[3];
		for (auto a: map)
		{
			int x = a.second;
			res[x].push_back(a.first);
		}

		string ans;
		int n = s.length();
		for (int i = n; i >0 ; i--)
		{
			for (int j = 0; j < res[i].size(); j++)
			{
				for (int k = 0; k < i; k++)
				{
					ans += res[i][j];
				}
			}
		}
		return ans;
	}
};

int main()
{
	solution solu;

	vector<int> nums = { 1,2,1 };
	string str = "eeeee";
	int target = 0;
	string result = solu.frequencySort(str);
	//cout << result << endl;

	system("pause");
	return 0;
}