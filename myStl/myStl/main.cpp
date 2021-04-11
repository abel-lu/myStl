#include<iostream>
#include<vector>
#include<string>
using namespace std;
//破解情报问题
string function(string& s)
{
	if (s.empty()) return 0;
	int size = s.size();
	char x = s[0];
	if ((x > 64) && (x < 91))
	{
		char move = x - 64;
		for (int i = 0; i < size; i++)
		{
			if ((s[i] > 64) && (s[i] < 91))
			{
				s[i] += move;
				s[i]>90? s[i] -= 26:s[i];
			}
			else if ((s[i] > 47) && (s[i] < 58))
			{
				move %= 10;
				s[i] += move;
				s[i] > 57 ? s[i] -= 10 : s[i];
			}
		}
	}
	else if ((x > 47) && (x < 58))
	{
		char move = x - '0';
		for (int i = 0; i < size; i++)
		{
			if ((s[i] > 64) && (s[i] < 91))
			{
				s[i] += move;
				s[i]>90 ? s[i] -= 26 : s[i];
			}
			else if ((s[i] > 47) && (s[i] < 58))
			{
				s[i] += move;
				s[i] > 57 ? s[i] -= 10 : s[i];
			}
		}
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			s[i] += 1;
		}	
	}
	return s;
}

int main()
{
	string x,s;
	cin >> x;

	s = function(x);
	cout << s;
	system("pause");
	return 0;

}