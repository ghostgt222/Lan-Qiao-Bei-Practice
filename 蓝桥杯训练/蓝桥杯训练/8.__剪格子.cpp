/*
题目描述
	本题的要求就是请你编程判定：对给定的m  x  n  的格子中的整数，是否可以分割为两个部分，使得这两个区域的数字和相等。
	如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。
	如果无法分割，则输出  0。
输入
	程序先读入两个整数  m  n  用空格分割  (m,n< 10)。
	表示表格的宽度和高度。
	接下来是n行，每行m个正整数，用空格分开。每个整数不大于10000。
输出
	输出一个整数，表示在所有解中，包含左上角的分割区可能包含的最小的格子数目。
样例输入
	3  3
	10  1  52
	20  30  1
	1  2  3
样例输出
	3
*/

#include<iostream>
#include<set>
#include<queue>
#include<string>
using namespace std;

int **map8;
int n8, m8;
int sum;	// 总数
class nodes {
public:
	char *sign = new char[n8*m8];// 标志灰色节点
	// 构造函数
	nodes() {
		for (int i = 0; i < n8*m8; i++)
			sign[i] = '0';
	}
	// 拷贝构造函数
	nodes(const nodes& copy) {
		sign = new char[n8*m8];
		for (int i = 0; i < n8*m8; i++)
			sign[i] = copy.sign[i];
	}
	~nodes() {
		delete[] sign;
	}
};
//class nodes {
//public:
//	char sign[100] = { '0' };
//	nodes() {
//		for (int i = 0; i < n8*m8; i++)
//			sign[i] = '0';
//	}
//};
int next_[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
set<string>st8;
queue<int>q8;

void dfs(nodes vs, int deep);

int main8() {
	cin >> m8 >> n8;
	map8 = new int*[n8];
	for (int i = 0; i < n8; i++)
		map8[i] = new int[m8];
	sum = 0;
	for (int i = 0; i < m8; i++)
		for (int j = 0; j < n8; j++) {
			cin >> map8[i][j];	// 输入
			sum += map8[i][j];
		}
	if (sum % 2 == 1)	// 奇数
		cout << 0 << endl;
	else {	// 偶数
		nodes vs;
		vs.sign[0] = '1';
		st8.insert(vs.sign);
		dfs(vs, 1);
		if (q8.empty())	// 不存在则返回 0
			cout << 0 << endl;
		else {			// 输出所有可能的最小值
			int min = q8.front();
			while (!q8.empty()) {
				if (min > q8.front())
					min = q8.front();
				q8.pop();
			}
			cout << min << endl;
		}
	}
	return 0;
}

void dfs(nodes vs, int deep) {
	int x, y, sum_temp = 0;
	for (int i = 0; i < n8*m8; i++) {// 求和
		if (vs.sign[i] == '1') {
			x = i / m8;
			y = i % m8;
			sum_temp += map8[x][y];
		}
	}
	if (sum_temp == sum / 2) {// 是否符合要求(sum/2)
		q8.push(deep);
		return;
	}
	if (sum_temp > sum / 2)// 超过一半则不符合
		return;
	for (int i = 0; i < m8*n8; i++) {// 所有点,因为每个灰色点都能延展出去
		if (vs.sign[i] == '1') {	//	是否为灰色节点
			x = i / m8;
			y = i % m8;
			for (int j = 0; j < 4; j++) {// 邻点
				int x_next = x + next_[j][0];
				int y_next = y + next_[j][1];
				int i_next = x_next * m8 + y_next;
				// 新节点是否符合条件
				if (x_next < n8 && x_next >= 0 && y_next >= 0 && y_next < m8 && vs.sign[i_next] == '0') {
					nodes v_next = vs;
					v_next.sign[i_next] = '1';
					// 是否重复
					if (!st8.count(v_next.sign)) {
						st8.insert(v_next.sign);
						dfs(v_next, deep + 1);
					}
				}
			}
		}
	}
}

