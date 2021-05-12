#include<iostream>
#include<vector>
#include <numeric>
using namespace std;



int divideCandy(vector<int>& grade)
{
	int size = grade.size();
	if(size < 2) return size;

	int n = grade.size();//
	vector<int> candy(n,1);

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

	vector<int> grade = {1,2,3,0,3,2,1};
	int candyNum=divideCandy(grade);
	cout << "candyNum " << candyNum <<" "<< endl;
	system("pause");
	return 0;
	
}