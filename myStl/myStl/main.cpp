#include<iostream>
using namespace std;

/*  ��Ϸ����
		1�����������ڵ����ӣ����ΪA,B,C��
		2��A�����ϴ��µ��ϰ�������״������n����ͬ��С��Բ�̡�
		3�����ڰ���������һ��һ���ƶ�������B�ϣ�����ÿ���ƶ�ͬһ�������϶����ܳ��ִ�������С�����Ϸ���
*/

//�ƶ�����
int count1=0;

void move(const char A,const char C) 
{
	count1++;
	cout << A<<"->"<< C << endl;
}

//��ŵ�����㺯��
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
	int numDisks;//Բ������
	cout << "input the number of disks" << endl;
	cin >> numDisks;
	hanNuoTa(numDisks, 'A', 'B', 'C');
	cout << count1 << endl;
	system("pause");
	return 0;

}