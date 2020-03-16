/*
题目描述
	X国的一段古城墙的顶端可以看成  2*N个格子组成的矩形（如下图所示），现需要把这些格子刷上保护漆。
	a c e
	b d f
	你可以从任意一个格子刷起，刷完一格，可以移动到和它相邻的格子（对角相邻也算数），但不能移动到较远的格子（因为油漆未干不能踩！）
	比如：a  d  b  c  e  f  就是合格的刷漆顺序。
	c  e  f  d  a  b  是另一种合适的方案。
	当已知  N  时，求总的方案数。当N较大时，结果会迅速增大，请把结果对  1000000007  (十亿零七)  取模。

输入
	输入数据为一个正整数（不大于1000）
输出
	输出数据为一个正整数。
样例输入
	3
样例输出
	96
*/

//************dfs超时***********
#include<iostream>
#include<queue>
using namespace std;

#define MOD19 1000000007
int n19;
int map19[2][1000];
int _next19[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1} };// 八个方向

int dfs19(int x, int y, int deep);

int main19() {
	cin >> n19;
	int sum = 0;
	for (int y = 0; y < n19 / 2; y++) {// 只需要算1/4即可，因为对称
		map19[0][y] = 1;
		sum += dfs19(0, y, 1);
		map19[0][y] = 0;
		sum %= MOD19;
	}
	sum = (sum * 4) % MOD19;
	if (n19 % 2) {// 如果n是奇数
		map19[0][n19 / 2] = 1;
		sum += (dfs19(0, n19 / 2, 1)) * 2;
		sum %= MOD19;
	}
	cout << sum << endl;
	return 0;
}

int dfs19(int x, int y, int deep) {
	if (deep == 2 * n19)// 格子全部刷完
		return 1;
	int sum = 0;
	for (int i = 0; i < 8; i++) {// 不同方向dfs
		int x_temp = x + _next19[i][0];
		int y_temp = y + _next19[i][1];
		if (x_temp >= 0 && x_temp < 2 && y_temp >= 0 && y_temp < n19&&map19[x_temp][y_temp] == 0) {// 符合要求的路径
			map19[x_temp][y_temp] = 1;	// 标记走过 
			sum += dfs19(x_temp, y_temp, deep + 1);
			map19[x_temp][y_temp] = 0;	// 去除标记
			sum %= MOD19;
		}
	}
	return sum % MOD19;
}