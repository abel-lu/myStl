#include<iostream>
using namespace std;


/*
�ṹ��������
	ÿ����Ԫ�Ĵ�Сȡ���ڽṹ�������������͵Ĵ�С��
	ÿ����Ԫ�Ĵ�С���������������͵���������
		���������������͵�Ԫ��int:ռ��4�ֽ�
		char�ַ�ռ��һ���ֽڣ���char name[20]ռ��20�ֽڣ���4��������
		char genderռ��һ���ֽڣ����ǿռ��ṩ4�ֽڵĿռ�
	����student�ṹ���ռ���ڴ�Ϊ4+20+4=28�ֽ�
*/
struct student
{
	int num;
	char name[20];
	char gender;
};

//����Ϳսṹ��һ��ռ��һ���ֽڣ�Ϊ�˷���һ�������ռ����ֲ�ͬ�Ŀն���
class emptyClass 
{
};

/*	���е����ݳ�ԱҲ���ڲ��룬��ṹ����������ƣ�������ı�׼���Ȳ��������࣬Ҳ������������볤�ȣ�
	��̬�����ݳ�Ա��ռ���ֽڣ�
	���캯����������������Ա��������ռ���ֽڣ�
*/
class virClass
{
	int i;
	char a[8];
	virtual void fun(){}
	/*�麯���ʹ��麯������ռ���ֽڣ���������ָ�룬��ʱռ�õĿռ�Ϊһ��ָ�볤�ȣ� ?
		64λ������ָ��ռ��8�ֽڣ�64/8
	�麯���ʹ��麯�� ??���ֽ�ռ������ ?һ����
	�޼̳�ʱ������麯�������麯������һ��ָ�룬ռ���ֽ�Ϊһ��ָ�볤�ȣ�
	�м̳�ʱ���м�����������麯������Ҫ���ٸ�ָ�룬��ʱ������麯�������麯������ռ���ֽڣ�
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
