#include<iostream>
#include<vector>
#include <numeric>
#include <algorithm>
using namespace std;
//反转二进制数字
//输入: 00000010100101000001111010011100
//	输出 : 00111001011110000010100101000000
//	解释 : 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
//	因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。

const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

int main()
{
	uint32_t x,y,n = 43261596;
	//计算顺序
	//x=(n >> 1)& M1; 取偶数位到奇数位
	//y =(n & M1)<<1;取奇数位到偶数位
	//n = x|y;结合，实现奇偶互换
	n = n >> 1 & M1 | (n & M1) << 1;
	n = n >> 2 & M2 | (n & M2) << 2;//实现两两互换
	n = n >> 4 & M4 | (n & M4) << 4;
	n = n >> 8 & M8 | (n & M8) << 8;
	system("pause");
	return 0;
	
}