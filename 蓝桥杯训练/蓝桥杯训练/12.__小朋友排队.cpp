/*
题目描述
	n  个小朋友站成一排。现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。

	每个小朋友都有一个不高兴的程度。开始的时候，所有小朋友的不高兴程度都是0。

	如果某个小朋友第一次被要求交换，则他的不高兴程度增加1，如果第二次要求他交换，则他的不高兴程度增加2（即不高兴程度为3），依次类推。当要求某个小朋友第k次交换时，他的不高兴程度增加k。

	请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。

	如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。

样例说明
	首先交换身高为3和2的小朋友，再交换身高为3和1的小朋友，再交换身高为2和1的小朋友，每个小朋友的不高兴程度都是3，总和为9。
	数据规模和约定
	对于100%的数据，1< =n< =100000，0< =Hi< =1000000。

输入
	输入的第一行包含一个整数n，表示小朋友的个数。
	第二行包含  n  个整数  H1  H2  …  Hn，分别表示每个小朋友的身高。
	输出
	输出一行，包含一个整数，表示小朋友的不高兴程度和的最小值。
样例输入
	3
	3  2  1
样例输出
	9

*/


#define correct
#ifdef correct
//*******树状数组算法*********
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100001

class Students {
public:
	int anxiety;
	int frequency;
	int high_temp;	// 原始高度
	int high;		// 离散后的高度
	int pos;
}stu[N];
int c[N];	// 树状数组
int n12;

bool cmp12(Students a, Students b) {
	return a.high_temp < b.high_temp;
}
void update(int idx, int num);
int perfixsum(int x);

int main12() {
	cin >> n12;
	for (int i = 1; i <= n12; i++) {
		cin >> stu[i].high_temp;
		stu[i].pos = i;
	}
	// 离散化
	sort(stu + 1, stu + n12 + 1, cmp12);	// 排序
	int cnt = 1;
	for (int i = 1; i <= n12; i++) {
		if (i != 1 && stu[i].high_temp != stu[i - 1].high_temp)// 处理重复数字
			cnt++;
		stu[stu[i].pos].high = cnt;
	}
	// 求正逆序数（前面有多少高于他）
	for (int i = 1; i <= n12; i++) {
		update(stu[i].high, 1);
		stu[i].frequency = i - perfixsum(stu[i].high);
	}
	memset(c, 0, sizeof(c));
	// 求反逆序数（后面有多少矮于他）
	for (int i = n12; i > 0; i--) {
		update(stu[i].high, 1);
		stu[i].frequency += perfixsum(stu[i].high - 1);
	}
	long long sum = 0;
	for (int i = 1; i <= n12; i++) {
		stu[i].anxiety = (stu[i].frequency + 1)*stu[i].frequency / 2;
		sum += stu[i].anxiety;
	}
	cout << sum << endl;
	return 0;
}
void update(int idx, int num) {
	while (idx < N) {
		c[idx] += num;
		idx = idx + (idx & -idx);
	}
}
int perfixsum(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += c[idx];
		idx = idx - (idx & -idx);
	}
	return sum;
}
#else
//*******插入排序超时********
#include<iostream>
using namespace std;
class Student {
public:
	int high;		// 高度
	int frequency = 0;// 被交换次数
	int anxiety;	// 不高兴程度
}stu[100000];
int n12;	//学生个数

void func12();

int main12() {
	cin >> n12;
	for (int i = 0; i < n12; i++)
		cin >> stu[i].high;
	func12();
	int sum = 0;

	for (int i = 0; i < n12; i++) {
		stu[i].anxiety = (stu[i].frequency + 1)*stu[i].frequency / 2;
		sum += stu[i].anxiety;
	}
	cout << sum << endl;
	return 0;
}

void func12() {// 插入排序
	int i, j;
	for (i = 1; i < n12; i++) {
		Student temp = stu[i];
		for (j = i; j > 0 && temp.high < stu[j - 1].high; j--) {
			stu[j - 1].frequency++;		// 被交换次数增加
			temp.frequency++;			// 被交换次数增加
			stu[j] = stu[j - 1];
		}
		stu[j] = temp;
	}
}
#endif
