#include<iostream>
#include<vector>
using namespace std;


int function(vector<vector<int>>& score)
{
	vector<int> grade(5, 0);
	int max, min;
	int n = score.size();
	for (int i = 0; i < 5; i++)
	{
		//取每个维度的第一本书值
		max = score[0][i];
		for (int j = 0; j < n; j++)
		{
			//获得每个维度最大值
			if (score[j][i] > max)
			{
				max = score[j][i];
			}
		}
		grade[i] = max;
	}
	min = grade[0];
	for (int i = 0; i < 5; i++)
	{
		if (min > grade[i])
		{
			min = grade[i];
		}
	}
	return min;
}

int main()
{
	int n;
	cin >> n;
	if (n < 1) return 0;
	//cout << n;
	vector<vector<int>> score(n, vector<int>(5, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> score[i][j];
		}
	}
	int grade = function(score);
	cout << grade;
	system("pause");
	return 0;

}