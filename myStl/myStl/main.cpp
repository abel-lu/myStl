#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

//给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
//
//输入: "abca"
//	输出 : True
//	解释 : 你可以删除c字符。

class solution
{
public:
	bool validPalindrome(string s) {
		string ss = s;
		int n = s.size();
		if (n < 2) return true;
		int count=0;
		int left=0,right=n-1,l1,r1;
		bool b1=true,b2=true;
		//判断字符串是否互文，如果不互文，分情况讨论
		while(left<right)
		{
			if (s[left] != s[right])
			{
				count++;
				break;
			}
			else
			{
				left++;
				right--;
			}
			
		}	
		//不互文的情况
		if (count > 0)
		{
			l1 = left;
			r1 = right-1;
			left++;
			//第一种，删除前面的
			while (left<right)
			{
				if (s[left] != s[right])
				{
					b1=false;
					break;
				}
				else
				{
					left++;
					right--;
				}

			}
			//第二种删除后面的
			while (l1<r1)
			{
				if (s[l1] != s[r1])
				{
					b2=false;
					break;
				}
				else
				{
					l1++;
					r1--;
				}
			}
		}
		//两种有一种可以互文即true
		return b1 || b2;
		
	}
};

int main()
{
	solution solu;

	string x = "abc";
	bool result=solu.validPalindrome(x);
	cout << result << endl;
	system("pause");
	return 0;

}