#include<iostream>
using namespace std;

/*  游戏规则
		1、有三根相邻的柱子，标号为A,B,C。
		2、A柱子上从下到上按金字塔状叠放着n个不同大小的圆盘。
		3、现在把所有盘子一个一个移动到柱子B上，并且每次移动同一根柱子上都不能出现大盘子在小盘子上方。
*/

//移动次数
int count1=0;

void move(const char A,const char C) 
{
	count1++;
	cout << A<<"->"<< C << endl;
}

//汉诺塔计算函数
int hanNuoTa(int n,const char A, const char B, const char C)
{
	if (n == 1)
	{
		move(A, C);	
		return 1;
	}
	else
	{
		hanNuoTa(n-1, A, C, B);
		move(A, C);
		hanNuoTa(n-1, B, A, C);
	}
	return 0;
	

}

int main()
{
	int numDisks;//圆盘数量
	cout << "input the number of disks" << endl;
	cin >> numDisks;
	hanNuoTa(numDisks, 'A', 'B', 'C');
	cout << count1 << endl;
	system("pause");
	return 0;

}