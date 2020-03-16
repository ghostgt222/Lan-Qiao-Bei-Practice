/*
问题描述
	有n个小朋友围坐成一圈。老师给每个小朋友随机发偶数个糖果，然后进行下面的游戏：

	每个小朋友都把自己的糖果分一半给左手边的孩子。

	一轮分糖后，拥有奇数颗糖的孩子由老师补给1个糖果，从而变成偶数。

	反复进行这个游戏，直到所有小朋友的糖果数都相同为止。

	你的任务是预测在已知的初始糖果情形下，老师一共需要补发多少个糖果。
输入
	程序首先读入一个整数N(2< N< 100)，表示小朋友的人数。
	接着是一行用空格分开的N个偶数（每个偶数不大于1000，不小于2）
输出
	要求程序输出一个整数，表示老师需要补发的糖果数。
样例输入
	3
	2  2  4
样例输出
	4
*/

#include<iostream>
using namespace std;

void circle(int *stu, int n);
int bufa(int *stu, int n);	 
int judge7(int *stu, int n);

int main7() {
	int n;
	cin >> n;
	int *stu = new int[n];
	for (int i = 0; i < n; i++)
		cin >> stu[i];
	int sum = 0;
	circle(stu, n);
	while (!judge7(stu, n)) {
		sum += bufa(stu, n);
		if (judge7(stu, n))
			break;
		circle(stu, n);
	}
	cout << sum << endl;
	return 0;
}
void circle(int *stu, int n) {// 分糖
	int *temp=new int[n];
	for (int i = 0; i < n; i++)
		temp[i] = stu[i];
	for (int i = 0; i < n - 1; i++) {
		stu[i + 1] += temp[i] / 2;
		stu[i] -= temp[i] / 2;
	}
	stu[0] += temp[n - 1] / 2;
	stu[n - 1] -= temp[n - 1] / 2;
}
int bufa(int *stu, int n) {// 补发糖果
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (stu[i] % 2 == 1) {
			stu[i] += 1;
			sum += 1;
		}
	}
	return sum;
}
int judge7(int *stu, int n) {// 是否符合要求
	int temp = stu[0];
	for (int i = 0; i < n; i++) {
		if (temp != stu[i])
			return 0;
	}
	return 1;
}