/*
输入
	输入第一行包含九宫的初态，第二行包含九宫的终态。
输出
	输出最少的步数，如果不存在方案，则输出-1。
样例输入
	12345678.
	123.46758
样例输出
	3
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<set>
#include<cstring>
#include<time.h>
using namespace std;

class node {
public:
	char str[9];
	int deep;
};
queue<node>q;
set<string> st1;	// 去重（灰色节点）

void func1(char *str, char *str_end, int count);
int swap1 (char *str, int choice);

int main1() {
	clock_t startTime, endTime;
	char str_start[9];
	char str_end[9];
	scanf("%s", str_start);
	scanf("%s", str_end);
	startTime = clock();	// 计时开始
	func1(str_start, str_end, 0);
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}

void func1(char *str, char *str_end, int count) {
	node vs, vd, v1, v2;
	strcpy(vs.str, str);	// 头节点
	vs.deep = 0;
	strcpy(vd.str, str);
	q.push(vs);
	while (!q.empty()) {
		v1 = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {// 所有可行路线
			strcpy(v2.str, v1.str);
			v2.deep = v1.deep + 1;
			int status = swap1(v2.str, i);	// 到达下一个节点（状态）
			// 判断是否已经达到最终状态
			if (!strcmp(v2.str, str_end)) {
				cout << v2.deep << endl;
				return;
			}
			// 是否为可行路线且为未曾走过
			if (status && (st1.count(v2.str) == 0)) {// 利用set去重
				st1.insert(v2.str);
				q.push(v2);
			}
		}
	}
	cout << -1 << endl;
	return;
}

int swap1(char *str, int choice) {
	char temp;
	for (int i = 0; i < 9; i++)
		if (str[i] == '.') {
			switch (choice) {
			case 0:	// 上
				if (i - 3 < 0)
					break;
				temp = str[i];
				str[i] = str[i - 3];
				str[i - 3] = temp;
				return 1;
				break;
			case 1:	// 下
				if (i + 3 > 8)
					break;
				temp = str[i];
				str[i] = str[i + 3];
				str[i + 3] = temp;
				return 1;
				break;
			case 2:	// 左
				if (i % 3 == 0)
					break;
				temp = str[i];
				str[i] = str[i - 1];
				str[i - 1] = temp;
				return 1;
				break;
			case 3:	// 右
				if (i % 3 == 2)
					break;
				temp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = temp;
				return 1;
				break;
			}
			return 0;
		}
}