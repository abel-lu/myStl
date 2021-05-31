#include<iostream>
#include<vector>
using namespace std;


void getNext(string s,vector<int>& next)
{

	next.push_back(0);
	int n = s.size();
	for (int i = 1,j=0; i < n;)
	{
		if (s[i] == s[j])
		{

			int x = next[i-1] + 1;
			next.push_back(x);
			j++;
			i++;
		}
		else
		{
			if (j == 0)
			{

				next.push_back(0);
				i++;
				j = 0;
			}
			else
			{
	
				j = 0;
			}
		}
	}
}


bool KMPmatch(string mstring, string sstring)
{
	vector<int> next;
	if(mstring.empty() && sstring.empty()) return true;
	if(mstring.empty() || sstring.empty()) return false;
	int m = mstring.size();
	int n = sstring.size();
	getNext(sstring, next);
	for (int i = 0, j = 0; i < m && j < n;)
	{
		if (mstring[i] == sstring[j])
		{

			i++;
			j++;

			if (j == n) 
				return true;
		}
		else
		{
			
			j == 0 ? i++ : j = next[j-1];
		}
	}

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

