#include<iostream>
using namespace std;

//全局变量的作用范围，一般是从定义位置开始到本程序文件的末尾。
//在此作用域内，全局变量可以为程序中各个函数所引用。
int i = 1;  //全局变量，静态存储区 。存在于程序的整个运行过程中。

//外部衔接性即：一个文件中定义了i全局变量，在另一个文件中用extern对i进行外部声明。
//全局变量用static声明，把该变量的作用域只限于本文件模块中，即取消外部衔接性。
static int k = 2;

int main(void)
{
	static int a;  // 静态局部变量，静态存储区；有全局寿命，局部可见。
	int b = -10;  // b, c为局部变量，具有动态生存期。
	int c = 0;
	void other(void);
	cout << "---MAIN---\n";
	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;//1 0 -10 0
	c = c + 8;  other();// 33 4 0 15
	cout << "---MAIN---\n";
	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;//33 0 -10 8 
	i = i + 10; other();  //75 6 4 15
	other(); //107 8 6 15
	system("pause");
	return 0;
}
void other(void)
{
	static int a = 2;
	static int b;
	// a,b为静态局部变量，具有全局寿命，局部可见。
	//只第一次进入函数时被初始化。
	int c = 10;   // C为局部变量，常量存储区，具有动态生存期
				  //每次进入函数时都初始化。
	a = a + 2; i = i + 32; c = c + 5;
	cout << "---OTHER---\n";
	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
	b = a;
}
