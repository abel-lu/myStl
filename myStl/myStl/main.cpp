#include<iostream>
using namespace std;


/*
结构体计算规则：
	每个单元的大小取决于结构体中最大基础类型的大小，
	每个单元的大小必须是最大基础类型的整数倍；
		上例中最大基础类型单元是int:占用4字节
		char字符占用一个字节，则char name[20]占用20字节，是4的整数倍
		char gender占用一个字节，但是空间提供4字节的空间
	所以student结构体的占用内存为4+20+4=28字节
*/
struct student
{
	int num;
	char name[20];
	char gender;
};

//空类和空结构体一样占用一个字节，为了分配一个单独空间区分不同的空对象
class emptyClass 
{
};

/*	类中的数据成员也存在补齐，与结构体中情况类似，但补齐的标准长度不仅看子类，也看父类的最大对齐长度；
	静态的数据成员不占用字节；
	构造函数、析构函数、成员函数都不占用字节；
*/
class virClass
{
	int i;
	char a[8];
	virtual void fun(){}
	/*虚函数和纯虚函数都不占用字节，但会申请指针，此时占用的空间为一个指针长度； ?
		64位编译器指针占用8字节，64/8
	虚函数和纯虚函数 ??“字节占用数” ?一样；
	无继承时，多个虚函数、纯虚函数共享一个指针，占用字节为一个指针长度；
	有继承时，有几个父类存在虚函数就需要多少个指针，此时子类的虚函数、纯虚函数不再占用字节；
	*/
};

int main(int argc, char const *argv[])
{
	
	student s = { 10,"asd",'M' };
	cout << s.num << endl;				//10
	cout << sizeof(s.num) << endl;		//4
	cout << sizeof(s.name) << endl;		//20
	cout << sizeof(s.gender) << endl;	//1
	cout << sizeof(s) << endl;			//28

	emptyClass ec;
	cout << sizeof(ec) << endl;			//1

	virClass vc;
	cout << sizeof(vc) << endl;			//16

	system("pause");					
	return 0;
}
