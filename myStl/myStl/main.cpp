#include<iostream>
using namespace std;

class A
{
public:
	static void f(A a);
private:
	//static int y = 0; ����->��̬��Ա���������ڳ�ʼ��
	//const int count = 0; ����->������ԱҲ���������ڳ�ʼ��
	static const int count = 0; // ��̬������Ա���������ڳ�ʼ��
	static int y;
	int x;
	int z = 0;
};

//��ľ�̬��Ա��static member�������������������������ʼ��
//��Ϊ��̬��Ա���������࣬��������ĳ��������������ڳ�ʼ��
//�ᵼ��ÿ�����󶼰����þ�̬��Ա������ì�ܵġ�
int A::y = 1;

void A::f(A a)
{

	//��̬��Ա����ֻ���������ڸ���ľ�̬���ݳ�Ա��̬��Ա������
	// cout<<x; //��x�������Ǵ����
	cout << a.x;  //��ȷ
}

class Point
{
public:
	Point(int xx = 0, int yy = 0) { X = xx; Y = yy; countP++; }
	Point(Point &p);//���صĹ��캯��
	static void getCountP() {
		cout<<countP;
		//X++: ���󣺾�̬��Ա�������ܵ��÷Ǿ�̬��Ա
	};
	//�Ǿ�̬��Ա�����ȿ��Ե��þ�̬��Ա��Ҳ���Ե��÷Ǿ�̬��Ա
	void getCountP1() {
		cout<<countP;
		X++;
	};

	int GetX() { return X; }
	int GetY() { return Y; }
	void GetC() { cout << " Object id=" << countP << endl; }
private:
	int X, Y;
	//��̬���ݳ�Ա���������ⲿ����ͳ�ʼ�����ڲ�����ֱ�ӳ�ʼ����
	static int countP;
};

Point::Point(Point &p)
{
	X = p.X;
	Y = p.Y;
	countP++;
}
//���������ⶨ��ͳ�ʼ������(::)��ָ���������ࡣ
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
