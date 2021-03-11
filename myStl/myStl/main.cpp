#include<iostream>
using namespace std;


enum weekday
{
	s, 
	m,
	t,
	w=6,
	thu,
	f,
	s1
};

int main(int argc, char const *argv[])
{
	enum weekday wek = s;
	weekday wek1= s;
	cout << wek1 << endl;;
	cout << t << endl;		//t没有赋值，输出枚举位置
	cout<< w<<endl;			//w赋值，输出值
	for (int i = wek; i != f; i++)
	{
		cout << i << endl;
		cout << wek + s << endl;
		cout << "--------------" << endl;
	}
	system("pause");
	return 0;
}

