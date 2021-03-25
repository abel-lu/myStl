#include<iostream>
#include<vector>
using namespace std;

//获取子串的next数组
void getNext(string s,vector<int>& next)
{
	//子串第一个匹配值一定为0
	next.push_back(0);
	int n = s.size();
	for (int i = 1,j=0; i < n;)
	{
		if (s[i] == s[j])
		{
			//如果前缀码匹配，next值加一
			int x = next[i-1] + 1;
			next.push_back(x);
			j++;
			i++;
		}
		else
		{
			if (j == 0)
			{
				//没有匹配到前缀码，一直push0，i++,j=0不动，继续下一个的匹配
				next.push_back(0);
				i++;
				j = 0;
			}
			else
			{
				//前面都是匹配的，出现不匹配后，j清0,i位置不变
				//从i位置再计算是否和j=0匹配
				j = 0;
			}
		}
	}
}

//KMP匹配算法
bool KMPmatch(string mstring, string sstring)
{
	vector<int> next;
	if(mstring.empty() && sstring.empty()) return true;
	if(mstring.empty() || sstring.empty()) return false;
	int m = mstring.size();
	int n = sstring.size();
	getNext(sstring, next);//获取子串next
	for (int i = 0, j = 0; i < m && j < n;)
	{
		if (mstring[i] == sstring[j])
		{
			//子串和木串匹配
			i++;
			j++;
			//子串全部匹配，返回true
			if (j == n) 
				return true;
		}
		else
		{
			//当前不匹配有两种情况，j=0时是前面也不匹配，子串没有移动过，母串i位置直接++即可
			//j!=0时，前面是匹配的，现在不匹配了，母串i位置不动，子串返回到next存储的位置。
			j == 0 ? i++ : j = next[j-1];
		}
	}
	//循环结束，没有完全匹配
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

