#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;
//
//有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，
//那么城市 a 与城市 c 间接相连。
//省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
//而 isConnected[i][j] = 0 表示二者不直接相连。
//返回矩阵中 省份 的数量。


//输入：isConnected = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
//输出：2

class solution
{
public:
	int dfs(vector<vector<int>>& isConnected,int i,int j)
	{
		int ans = 0, num = 0;
		isConnected[i][j] = 0;
		for (int k = 0; k < isConnected.size(); k++)
		{
			if (isConnected[j][k] == 1)
			{
				num++;
				ans+=dfs(isConnected, i, j);
			}
		}
		return ans;
	}
	int findCircleNum(vector<vector<int>>& isConnected) {
		//两个城市如果相连，（i,j）和(j,i)都是1 ,只检索一个,即对角线检索
		int cityNum = isConnected.size();//城市数量即矩阵行数，且矩阵行列相同。
		int conNum=0;
		for (int i = 0; i < cityNum; i++)
		{
			//j==i，即对角线检索
			for (int j = i; j < cityNum; j++)
			{
				//对角线对应自己，肯定为1，不搜索
				if (i == j)
				{
					continue;
				}
				dfs(isConnected, i, j);
				if (isConnected[i][j] == 1)
				{

				}
			}
		}
	}
};

int main()
{
	solution solu;

	vector<int> nums = { 2,0,2,1,1,0 };
	vector<vector<int>> num = { {1,1,0},{1,1,0},{0,0,1} };
	string str = "eeeee";
	int target = 0;
	int result=solu.findCircleNum(num);
	//cout << result << endl;

	system("pause");
	return 0;
}