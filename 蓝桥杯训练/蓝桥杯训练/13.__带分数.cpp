/*
题目描述
	100  可以表示为带分数的形式：100  =  3  +  69258  /  714。
	还可以表示为：100  =  82  +  3546  /  197。
	注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。
	类似这样的带分数，100  有  11  种表示法。
输入
	从标准输入读入一个正整数N  (N< 1000*1000)
输出
	程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
	注意：不要求输出每个表示，只统计有多少表示法！
样例输入
	100
样例输出
	11
*/

#include<iostream>
using namespace std;

void allchoice13(int deep);	// 遍历所有组合
void judge13();				// 判断
void str2num(int index1, int index2, int *a, int *b, int *c);

int n13;
int num13[9];			//存储数组
bool sign9[9] = { 0 };	//标志数字是否使用
int sum13 = 0;

int main13() {
	cin >> n13;
	allchoice13(1);
	cout << sum13 << endl;
	return 0;
}
void allchoice13(int deep) {
	if (deep == 10) {
		judge13();
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (sign9[i] == 0) {
			num13[deep - 1] = i + 1;
			sign9[i] = 1;	// 标记数字被使用
			allchoice13(deep + 1);
			sign9[i] = 0;	// 可以再次被使用
		}
	}
}
void judge13() {
	for (int i = 1; i < 9; i++) {// 将数组从i和j处切割分为a、b、c三个数字
		for (int j = 8; j > 8 - (9 - i) / 2; j--) {// 8-(9-i)/2保证分子比分母位数多
			int a = 0, b = 0, c = 0;
			str2num(i, j, &a, &b, &c);
			if (b%c != 0)	// b/c是小数
				continue;
			if (a + b / c == n13)	// 满足条件
				sum13++;
		}
	}
}
void str2num(int index1, int index2, int *a, int *b, int *c) {
	for (int i = 0; i < index1; i++)
		*a = (*a) * 10 + num13[i];
	for (int i = index1; i < index2; i++)
		*b = (*b) * 10 + num13[i];
	for (int i = index2; i < 9; i++)
		*c = (*c) * 10 + num13[i];
}