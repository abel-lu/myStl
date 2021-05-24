#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

////给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
//
//输入：c = 5
//输出：true
//解释：1 * 1 + 2 * 2 = 5

class solution
{
public:
	bool judgeSquareSum(int c) {
		if (c == 0) return true;
		int s = sqrt(c);
		long i, j;
		while(i <= j)
		{
			if ((j*j + i*i) == c)
			{
				return true;
			}
			else if ((j*j + i*i) > c)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return false;
	}
};

int main()
{
	solution solu;

	int x = 5;
	bool result=solu.judgeSquareSum(x);
	cout << result << endl;
	system("pause");
	return 0;

}