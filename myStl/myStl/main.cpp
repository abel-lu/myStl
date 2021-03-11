#include<iostream>
using namespace std;

class A
{
public:
	static void f(A a);
private:
	//static int y = 0; 错误->静态成员不能在类内初始化
	//const int count = 0; 错误->常量成员也不能在类内初始化
	static const int count = 0; // 静态常量成员可以在类内初始化
	static int y;
	int x;
	int z = 0;
};

//类的静态成员（static member）必须在类内声明，在类外初始化
//因为静态成员属于整个类，而不属于某个对象，如果在类内初始化
//会导致每个对象都包含该静态成员，这是矛盾的。
int A::y = 1;

void A::f(A a)
{

	//静态成员函数只能引用属于该类的静态数据成员或静态成员函数。
	// cout<<x; //对x的引用是错误的
	cout << a.x;  //正确
}

class Point
{
public:
	Point(int xx = 0, int yy = 0) { X = xx; Y = yy; countP++; }
	Point(Point &p);//重载的构造函数
	static void getCountP() {
		cout<<countP;
		//X++: 错误：静态成员函数不能调用非静态成员
	};
	//非静态成员函数既可以调用静态成员，也可以调用非静态成员
	void getCountP1() {
		cout<<countP;
		X++;
	};

	int GetX() { return X; }
	int GetY() { return Y; }
	void GetC() { cout << " Object id=" << countP << endl; }
private:
	int X, Y;
	//静态数据成员，必须在外部定义和初始化，内部不能直接初始化！
	static int countP;
};

Point::Point(Point &p)
{
	X = p.X;
	Y = p.Y;
	countP++;
}
//必须在类外定义和初始化，用(::)来指明所属的类。
int Point::countP = 0;
int main(int argc, char const *argv[])
{
	A a;
	a.f(A());

	Point A(4, 5);
	cout << "Point A," << A.GetX() << "," << A.GetY();
	A.GetC();
	Point B(A);
	cout << "Point B," << B.GetX() << "," << B.GetY();
	B.GetC();
	B.getCountP();
	system("pause");
	return 0;
}
