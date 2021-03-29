#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

//һȺ����վ��һ�ţ�ÿһ���������Լ������֡�������Ҫ����Щ���ӷ��ǹ������������һ
//�����ӵ����ֱ��Լ����Ե�һ������Ҫ�ߣ���ô������Ӿͱ���õ������Ժ��Ӹ�����ǹ�����
//�к�������Ҫ��һ���ǹ������������Ҫ���ٸ��ǹ�

int divideCandy(vector<int>& grade)
{
	int size = grade.size();
	if(size < 2) return size;

	int n = grade.size();//n��С����
	vector<int> candy(n,1);
	/*˼·��
		�����ұ������Ҳ�����ߵĺ��ӱ���ߺ��Ӷ�һ��
		�٣����ҵ��������
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
	//���ӵ����֣���˳��
	vector<int> grade = {1,2,3,0,3,2,1};//ʵ�ʷ��ǹ����Ϊ1 2 3 1 3 2 1=13
	int candyNum=divideCandy(grade);
	cout << "һ����Ҫ�ǹ�" << candyNum <<"��"<< endl;
	system("pause");
	return 0;
	
}