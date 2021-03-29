#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

//一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
//个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
//有孩子至少要有一个糖果。求解最少需要多少个糖果

int divideCandy(vector<int>& grade)
{
	int size = grade.size();
	if(size < 2) return size;

	int n = grade.size();//n个小朋友
	vector<int> candy(n,1);
	/*思路：
		从左到右遍历，右侧分数高的孩子比左边孩子多一个
		再，从右到左遍历，
	*/
	for (int i = 0; i < n-1 ; i++)
	{
		(grade[i+1] > grade[i]) ? candy[i+1]= candy[i]+1:i;
	}
	for (int i = n-1; i > 0; i--)
	{
		if (grade[i-1] > grade[i])
		{
			if (!(candy[i-1] > candy[i]))
				candy[i-1] = candy[i]+1;
		}
	}
	int sum = accumulate(candy.begin(), candy.end(), 0);
	return sum;
}

int main()
{
	//孩子的评分（有顺序）
	vector<int> grade = {1,2,3,0,3,2,1};//实际分糖果结果为1 2 3 1 3 2 1=13
	int candyNum=divideCandy(grade);
	cout << "一共需要糖果" << candyNum <<"个"<< endl;
	system("pause");
	return 0;
	
}