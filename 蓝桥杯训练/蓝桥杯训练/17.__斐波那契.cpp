/*
题目描述
	斐波那契数列大家都非常熟悉。它的定义是：

	f(x)  =  1  ....  (x=1,2)
	f(x)  =  f(x-1)  +  f(x-2)  ....  (x> 2)

	对于给定的整数  n  和  m，我们希望求出：
	f(1)  +  f(2)  +  ...  +  f(n)  的值。但这个值可能非常大，所以我们把它对  f(m)  取模。
	但这个数字依然很大，所以需要再对  p  求模。
输入
	输入为一行用空格分开的整数  n  m  p  (0  <   n,  m,  p  <   10^18)
输出
	输出为1个整数，表示答案
样例输入
	2  3  5
样例输出
	0
*/

//********超时*********
#include <iostream>
#include<time.h>
using namespace std;

long long n17, m17, p17;

void fib17();

int main17() {
	cin >> n17 >> m17 >> p17;
	// clock_t startTime, endTime;
	// startTime = clock();
	fib17();
	// endTime = clock();
	// cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}

void fib17() {
	unsigned long long fm, fn;	// f(m),f(n)
	unsigned long long f1, f2, f3;	// 储存f(x-2),f(x-1)和f(x)
	long long count = 3;	// 第count个斐波那契数
	unsigned long long sum = 2;
	f1 = 1;
	f2 = 1;
	while (count <= n17 || count <= m17) {
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		if (count <= n17)
			sum += f3;
		if (count == m17)
			fm = f3;	// 储存f(m)
		if (count == n17)
			fn = f3;	// 储存f(n)
		count++;
	}
	cout << sum % fm%p17 << endl;
}
