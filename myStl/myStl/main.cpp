#include<iostream>
using namespace std;

class A 
{
public:
	//���캯��
	A(int a, int b)
	{
		R1 = a;
		R2 = b;
	}
	//const���ֳ�Ա���غ���
	void print();
	void print() const;

	int x;
	int y;

private:
	int R1, R2;
};
void A::print()
{
	cout << "��ͨ����" << endl;
	cout << R1 << ":" << R2 << endl;
}
//ʵ����Ҳ��Ҫ����
void A::print() const
{
	cout << "���������" << endl;
	cout << R1 << ";" << R2 << endl;
}

int main()
{
	int *p;//�Ϸ���ָ����Բ���ʼ��
	//int &a;//���Ϸ������ñ����ʼ��
	//int &a = 3;//���Ϸ����ǳ������õĳ�ʼֵ����Ϊ��ֵ
	int x = 0;
	int &c = x;//�Ϸ�

	A const aclass(1,1);//������,���ܱ�����
	//aclass.x = 0;//���Ϸ���
	//cout << aclass.x << endl;

	A a(5, 4);
	a.print();  //����void print()
	//ֻ����ͨ����������ó���Ա����
	const A b(20, 52);
	b.print();  //����void print() const

	system("pause");
	return 0;
	
}