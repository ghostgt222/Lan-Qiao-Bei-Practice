/*
题目描述
	幸运数是波兰数学家乌拉姆命名的。它采用与生成素数类似的“筛法”生成
	。
	首先从1开始写出自然数1,2,3,4,5,6,....
	1  就是第一个幸运数。
	我们从2这个数开始。把所有序号能被2整除的项删除，变为：
	1  _  3  _  5  _  7  _  9  ....
	把它们缩紧，重新记序，为：
	1  3  5  7  9  ....  。
	这时，3为第2个幸运数，然后把所有能被3整除的序号位置的数删去。注意，是序号位置，不是那个数本身能否被3整除!!  删除的应该是
	5，11,  17,  ...
	此时7为第3个幸运数，然后再删去序号位置能被7整除的(19,39,...)
	最后剩下的序列类似：
	1,  3,  7,  9,  13,  15,  21,  25,  31,  33,  37,  43,  49,  51,  63,  67,  69,  73,  75,  79,  ...
输入
	输入两个正整数m  n,  用空格分开  (m  <   n  <   1000*1000)
输出
	程序输出  位于m和n之间的幸运数的个数（不包含m和n）。
样例输入
	30  69
样例输出
	8
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1000000

int m16, n16;
char arr16[N];

int func16();

int main16() {
	cin >> m16 >> n16;
	memset(arr16, 1, sizeof(arr16));// 未被删除的序号标记为1
	cout << func16() << endl;
	return 0;
}

int func16() {
	for (int i = 0; i < N; i++)// 将偶数去掉
		if (i % 2 == 0)
			arr16[i] = 0;
	// 从第二个幸运数字开始
	int flag = 3;		// 可被flag整除的数字删除
	int sign = 1;		// 1代表flag可被修改
	int count = 2;	// 代表第count个幸运数字
	for (int i = 1, j = 0; i < n16; i++) {
		if (arr16[i])		// 如果为1则说明该序号存在
			j++;		// j代表删除后的序列
		if (j == count && sign == 1) {		// 第二个数字
			flag = i;
			sign = 0;	// 在下一轮开始前flag不可修改
		}
		if (j%flag == 0)	// 删除数字
			arr16[i] = 0;
		if (i == n16 - 1) {// 到达终点
			if (count >= j)	// 中止循环
				break;
			i = 0;
			j = 0;
			sign = 1;	// 下一轮flag可修改
			count++;// 下一个幸运数字
		}

	}
	int sum = 0;
	for (int i = m16 + 1; i < n16; i++)
		if (arr16[i])
			sum++;
	return sum;
}