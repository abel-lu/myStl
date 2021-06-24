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
//给定一个包含了一些 0 和 1 的非空二维数组 grid 。
//
//一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。
//你可以假设 grid 的四个边缘都被 0（代表水）包围着。

//找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

//[[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]

//6
class Solution {
public:
	
};



class solution
{
public:
	int dfs(vector<vector<int>>& grid, int cur_x, int cur_y)
	{
		int width = grid.size();
		int height = grid[0].size();
		int ans=1;
		//返回0情况：1.超出边界，2.没有土地，0
		if (cur_x < 0 || cur_y < 0 || cur_x >= width || cur_y >= height|| grid[cur_x][cur_y] == 0)
		{
			return 0;
		}
		grid[cur_x][cur_y] = 0;
		int dx[4] = { 0,0 ,1,-1 };
		int dy[4] = { 1,-1,0,0 };
		//遍历四个方向，寻找土地
		for (int index = 0; index < 4;index++)
		{
			int next_x = cur_x + dx[index], next_y = cur_y + dy[index];
			ans += dfs(grid, next_x, next_y);
		}
		return ans;    
	
	}
	//方法1,深度优先搜索
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int width = grid.size();
		int height = grid[0].size();
		int ans = 0;
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
					ans=max(ans,dfs(grid, i, j));
			}
		}
		return ans;
	}



	//方法2，深度优先，用栈
	int maxAreaOfIsland3(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i != grid.size(); ++i) {
			for (int j = 0; j != grid[0].size(); ++j) {
				int cur = 0;
				stack<int> stacki;
				stack<int> stackj;
				stacki.push(i); 
				stackj.push(j);
				while (!stacki.empty()) {
					int cur_i = stacki.top(), cur_j = stackj.top();
					stacki.pop();
					stackj.pop();
					if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
						continue;
					}
					++cur;
					grid[cur_i][cur_j] = 0;
					int di[4] = { 0, 0, 1, -1 };
					int dj[4] = { 1, -1, 0, 0 };
					for (int index = 0; index != 4; ++index) {
						int next_i = cur_i + di[index], next_j = cur_j + dj[index];
						stacki.push(next_i);
						stackj.push(next_j);
					}
				}
				ans = max(ans, cur);
			}
		}
		return ans;
	}

	//方法3，广度优先搜索，用队列
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (int i = 0; i != grid.size(); ++i) {
			for (int j = 0; j != grid[0].size(); ++j) {
				int cur = 0;
				queue<int> queuei;
				queue<int> queuej;
				queuei.push(i);
				queuej.push(j);
				while (!queuei.empty()) {
					int cur_i = queuei.front(), cur_j = queuej.front();
					queuei.pop();
					queuej.pop();
					if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
						continue;
					}
					++cur;
					grid[cur_i][cur_j] = 0;
					int di[4] = { 0, 0, 1, -1 };
					int dj[4] = { 1, -1, 0, 0 };
					for (int index = 0; index != 4; ++index) {
						int next_i = cur_i + di[index], next_j = cur_j + dj[index];
						queuei.push(next_i);
						queuej.push(next_j);
					}
				}
				ans = max(ans, cur);
			}
		}
		return ans;
	}

};

int main()
{
	solution solu;

	vector<int> nums = { 2,0,2,1,1,0 };
	vector<vector<int>> num = { {0,0,0,1},{0,1,1,0},{0,1,0,1} };
	string str = "eeeee";
	int target = 0;
	int result=solu.maxAreaOfIsland2(num);
	//cout << result << endl;

	system("pause");
	return 0;
}