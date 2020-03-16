/*
题目描述
	有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？

输入
	输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
	n=0表示输入数据的结束，不做处理。

输出
	对于每个测试实例，输出在第n年的时候母牛的数量。
	每个输出占一行。

样例输入
	2
	4
	5
	0
样例输出
	2
	4
	6
*/

#include<iostream>
#include<deque>
#include<time.h>
using namespace std;

int result[1000] = { 0 };	//保存节点状态

int func2(int n) {
	int sum = 0;
	if (n == 1 || n == 2 || n == 3)
		return n;
	if (result[n] != 0)
		return result[n];
	if (n >= 4)
		sum = func2(n - 1) + func2(n - 3);	//递归
	result[n] = sum;
	return sum;
}

int main2() {
	clock_t startTime, endTime;
	int i, j;
	int n;
	deque<int> q;
	cin >> n;
	startTime = clock();
	while (n != 0) {
		q.push_front(func2(n));
		cin >> n;
	}
	//输出结果
	while (!q.empty()) {
		cout << q.back() << endl;
		q.pop_back();
	}
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}

