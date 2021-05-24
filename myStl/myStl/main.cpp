﻿#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//
//注意：如果 s 中存在这样的子串，我们保证它是唯一的答案


//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//
//输入：s = "a", t = "a"
//输出："a"

class solution
{
public:
	string minWindow(string s, string t) {
		int ss = s.size();
		int tt = t.size();
		if (ss == 0 || tt == 0 || ss < tt) return "";
		unordered_map<char, int> map,need;
		//用，map存储t
		for (auto x : t)
		{
			map[x]++;
		}
		//need = map;
		int left = 0, right = 0, pos;
		int count=0,min=ss+1;
		while (right < ss)
		{
			char a = s[right];
			if (map[a] == 0)
			{

				right++;
				continue;
				/*map[a]--;
				pos = left;
				dis=right-left;*/
			}
			if (need[a] < map[a])
			{
				count++;
			}
			need[a]++;
			right++;

			while (count == tt)
			{
				if (right - left < min)
				{
					min = right - left;
					pos = left;
				}

				char b = s[left];
				if (map[b] == 0)
				{
					left++;
					continue;
				}
				if (need[b] == map[b])
				{
					count--;
				}
				need[b]--;
				left++;
			}
			
			
		}
		if (min == ss+1)
		{
			return "";
		}
		return s.substr(pos, min);
		
	}
};

int main()
{
	solution solu;

	string s = "ADOBECODEBANC";
	string t = "ABC";

	string result=solu.minWindow(s,t);
	cout << result << endl;
	system("pause");
	return 0;

}