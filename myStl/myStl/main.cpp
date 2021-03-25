#include<iostream>
#include<vector>
using namespace std;

//��ȡ�Ӵ���next����
void getNext(string s,vector<int>& next)
{
	//�Ӵ���һ��ƥ��ֵһ��Ϊ0
	next.push_back(0);
	int n = s.size();
	for (int i = 1,j=0; i < n;)
	{
		if (s[i] == s[j])
		{
			//���ǰ׺��ƥ�䣬nextֵ��һ
			int x = next[i-1] + 1;
			next.push_back(x);
			j++;
			i++;
		}
		else
		{
			if (j == 0)
			{
				//û��ƥ�䵽ǰ׺�룬һֱpush0��i++,j=0������������һ����ƥ��
				next.push_back(0);
				i++;
				j = 0;
			}
			else
			{
				//ǰ�涼��ƥ��ģ����ֲ�ƥ���j��0,iλ�ò���
				//��iλ���ټ����Ƿ��j=0ƥ��
				j = 0;
			}
		}
	}
}

//KMPƥ���㷨
bool KMPmatch(string mstring, string sstring)
{
	vector<int> next;
	if(mstring.empty() && sstring.empty()) return true;
	if(mstring.empty() || sstring.empty()) return false;
	int m = mstring.size();
	int n = sstring.size();
	getNext(sstring, next);//��ȡ�Ӵ�next
	for (int i = 0, j = 0; i < m && j < n;)
	{
		if (mstring[i] == sstring[j])
		{
			//�Ӵ���ľ��ƥ��
			i++;
			j++;
			//�Ӵ�ȫ��ƥ�䣬����true
			if (j == n) 
				return true;
		}
		else
		{
			//��ǰ��ƥ�������������j=0ʱ��ǰ��Ҳ��ƥ�䣬�Ӵ�û���ƶ�����ĸ��iλ��ֱ��++����
			//j!=0ʱ��ǰ����ƥ��ģ����ڲ�ƥ���ˣ�ĸ��iλ�ò������Ӵ����ص�next�洢��λ�á�
			j == 0 ? i++ : j = next[j-1];
		}
	}
	//ѭ��������û����ȫƥ��
	return false;
}
int main() {
	string matherString = "eeebdeeebe";
	string	sonString="eeebe";
	bool bMatch=KMPmatch(matherString, sonString);
	cout << bMatch;
	system("pause");
	return 0;
}

