#include<iostream>
#include<vector>
#include <numeric>
#include <algorithm>
using namespace std;
//����������䣬��������Щ���以���ص�����Ҫ�Ƴ���������ٸ�������ֹ���������ص���
//��β���������ص�
//����:����[[1,2][2,4][1,3]]
//���һ����������ʾ��Ҫ�Ƴ�����������


//˼·�����������䰴�������������αȽ����䣬�����һ�������ǰһ���ص���ֱ���Ƴ���һ�����伴��ʵ�ֹ���
int eraseOverlap(vector<vector<int>>& input)
{
	if (input.empty())
	{
		return 0;
	}
	int size = input.size();
	//�Զ���������򣺰�������ڶ���ֵ�Ĵ�С���У��ڱ����м��������β��������
	sort(input.begin(), input.end(), [](vector<int> a, vector<int> b) {
		return a[1] < b[1];
	});
	int pre = input[0][1];
	int count=0;//��Ҫ�Ƴ����������
	for (int i = 1; i < size; i++)
	{
		//�����һ�����䳬��ǰһ�����䣬ֱ���Ƴ���һ��
		if (input[i][0] < pre )
		{
			count++;
		}
		else
		{
			//���䲻�ص�������preΪ��ǰ����Ľ�β
			pre = input[i][1];
		}
	}
	return count;
}

int main()
{
	vector<vector<int>> input = { {1,2},{2,4},{1,3},{1,4} };
	int num=eraseOverlap(input);
	cout << "�Ƴ�" << num << "������" << endl;
	system("pause");
	return 0;
	
}