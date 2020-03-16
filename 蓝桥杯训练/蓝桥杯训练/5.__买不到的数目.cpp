/*
题目描述
	小明开了一家糖果店。他别出心裁：把水果糖包成4颗一包和7颗一包的两种。糖果不能拆包卖。
	小朋友来买糖的时候，他就用这两种包装来组合。当然有些糖果数目是无法组合出来的，比如要买  10  颗糖。
	你可以用计算机测试一下，在这种包装情况下，最大不能买到的数量是17。大于17的任何数字都可以用4和7组合出来。
	本题的要求就是在已知两个包装的数量时，求最大不能组合出的数字。
输入
	两个正整数，表示每种包装中糖的颗数(都不多于1000)
输出
	一个正整数，表示最大不能买到的糖数
样例输入
	4  7
样例输出
	17
*/

#include<iostream>
using namespace std;

void func5(int a, int b);
int gcd(int a, int b);
bool judge5(int num, int a, int b);

int main5() {
	int a, b;
	cin >> a >> b;
	func5(a, b);
	return 0;
}

void func5(int a, int b) {
	int max = a * b / gcd(a, b);	//最小公倍数确定上界
	for (int i = max; i > 0; i--)
		if (!judge5(i, a, b)) {
			cout << i << endl;
			return;
		}
}

int gcd(int a, int b) {
	if (a%b == 0)
		return b;
	return gcd(b, a%b);
}

bool judge5(int num, int a, int b) {
	int m = num / a;
	int n = num / b;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			if ((i * a + j * b) == num)
				return true;
	return false;
}