#include<iostream>
using namespace std;

class A 
{
public:
	//构造函数
	A(int a, int b)
	{
		R1 = a;
		R2 = b;
	}
	//const区分成员重载函数
	void print();
	void print() const;

	int x;
	int y;

private:
	int R1, R2;
};
void A::print()
{
	cout << "普通调用" << endl;
	cout << R1 << ":" << R2 << endl;
}
//实例化也需要带上
void A::print() const
{
	cout << "常对象调用" << endl;
	cout << R1 << ";" << R2 << endl;
}

int main()
{
	int *p;//合法，指针可以不初始化
	//int &a;//不合法，引用必须初始化
	//int &a = 3;//不合法，非常量引用的初始值必须为左值
	int x = 0;
	int &c = x;//合法

	A const aclass(1,1);//常对象,不能被更新
	//aclass.x = 0;//不合法，
	//cout << aclass.x << endl;

	A a(5, 4);
	a.print();  //调用void print()
	//只能能通过常对象调用常成员函数
	const A b(20, 52);
	b.print();  //调用void print() const

	system("pause");
	return 0;
	
}