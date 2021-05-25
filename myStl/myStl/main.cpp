#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

//给定一个字符串和一个字符串字典，找到字典里面最长的字符串，
//该字符串可以通过删除给定字符串的某些字符来得到。
//如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。


/*输入:
s = "abpcplea", d = ["ale", "apple", "monkey", "plea"]

输出 :
	"apple"
*/

class solution
{
public:
	string findLongestWord(string s, vector<string>& dictionary) {
		unordered_map<char, int> smap,temp;
		int n = s.size();
		int count,max=0,pos=-1;
		//储存s的map
		for (int i = 0; i < n; i++)
		{
			smap[s[i]]++;
		}
		int d = dictionary.size();
		for (int i = 0; i < d; i++)
		{
			count = 0;
			temp = smap;
			string str = dictionary[i];
			for (int j = 0,l=0; j < str.size(),l<n;)
			{
				//判断是否是子串
				if (str[j] == s[l])
				{
					count++;
					l++;
					j++;
				}
				else
				{
					l++;
				}
			}
			if (count < str.size())
			{
				count = 0;
			}
			//判断字符串最长，或者字典序最短
			if (count >= max)
			{
				if (count == max)
				{
					for (int k = 0; k < count; k++)
					{
						if (dictionary[pos][k] > dictionary[i][k])
						{
							pos = i;
							break;
						}
						else if(dictionary[pos][k] < dictionary[i][k])
						{
							break;
						}
					}
				}
				else {
					//优先字符串最长，然后是位置
					max = count;
					pos = i;
				}
			}
		}
		if (pos == -1) return "";
		return dictionary[pos];
	}
};

int main()
{
	solution solu;

	string s = "aewfafwafjlwajflwajflwafj";
	vector<string> dictionary = { "apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};
	string result = solu.findLongestWord(s, dictionary);
	cout << result << endl;
	system("pause");
	return 0;

}