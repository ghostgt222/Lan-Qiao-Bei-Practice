/*
问题描述
	给定n个十六进制正整数，输出它们对应的八进制数。

输入格式
	输入的第一行为一个正整数n （1 <= n <= 10）。
	接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。

输出格式
	输出n行，每行为输入对应的八进制正整数。

【注意】
	输入的十六进制数不会有前导0，比如012A。
	输出的八进制数也不能有前导0。

样例输入
	2
	39
	123ABC

样例输出
	71
	4435274
*/

#include<iostream>
#include<string>
using namespace std;

void func3(string arr);
void m_int(char a, string *two);

int main3() {
	int n;
	cin >> n;
	string *arr = new string[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		func3(arr[i]);
	return 0;
}
void func3(string arr) {
	string two;	//二进制字符串
	int ba = 0;
	//转化为二进制
	for (int i = 0; arr[i] != '\0'; i++)
		m_int(arr[i], &two);
	//补足为3的倍数
	if (two.size() % 3 == 2)
		two = "0" + two;
	if (two.size() % 3 == 1)
		two = "00" + two;
	//转化为八进制并输出
	for (int i = 0; i < two.size(); i += 3) {
		ba = two[i + 2] - '0' + (two[i + 1] - '0') * 2 + (two[i] - '0') * 4;
		//若开头为0则不输出
		if (i != 0 || ba != 0)
			cout << ba;
		ba = 0;
	}
	cout << endl;
}

void m_int(char a, string *two) {
	switch (a)
	{
	case '0':*two += "0000"; break;
	case '1':*two += "0001"; break;
	case '2':*two += "0010"; break;
	case '3':*two += "0011"; break;
	case '4':*two += "0100"; break;
	case '5':*two += "0101"; break;
	case '6':*two += "0110"; break;
	case '7':*two += "0111"; break;
	case '8':*two += "1000"; break;
	case '9':*two += "1001"; break;
	case 'A':*two += "1010"; break;
	case 'B':*two += "1011"; break;
	case 'C':*two += "1100"; break;
	case 'D':*two += "1101"; break;
	case 'E':*two += "1110"; break;
	case 'F':*two += "1111"; break;
	}
}

