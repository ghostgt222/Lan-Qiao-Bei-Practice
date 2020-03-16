/*
问题描述
　　	  从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
　　	  注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
样例输入
	FFFF
样例输出
	65535
*/
#include<iostream>
#include<string>
using namespace std;

void func4(string arr);
int m_int(char a);

int main4() {
	string arr;
	cin >> arr;
	func4(arr);
	return 0;
}
void func4(string arr) {
	long long sum = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		sum = sum * 16 + m_int(arr[i]);
	}
	cout << sum << endl;
}

int m_int(char a) {
	switch (a)
	{
	case 'A':return 10;
	case 'B':return 11;
	case 'C':return 12;
	case 'D':return 13;
	case 'E':return 14;
	case 'F':return 15;
	default:return (a - '0');
	}
}

