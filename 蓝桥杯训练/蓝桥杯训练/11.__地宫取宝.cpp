/*
题目描述
	X国王有一个地宫宝库。是  n  *  m  个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。

	地宫的入口在左上角，出口在右下角。

	小明被带到地宫的入口，国王要求他只能向右或向下行走。

	走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。

	当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。

	请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。
输入
	输入一行3个整数，用空格分开：n  m  k  (1< =n,m< =50,  1< =k< =12)

	接下来有  n  行数据，每行有  m  个整数  Ci  (0< =Ci< =12)代表这个格子上的宝物的价值
输出
	要求输出一个整数，表示正好取k个宝贝的行动方案数。该数字可能很大，输出它对  1000000007  取模的结果。
样例输入
	2  3  2
	1  2  3
	2  1  5
样例输出
	14
*/

#include<iostream>
#include<cstring>
using namespace std;

int n11, m11, k11;	
int map11[50][50];		// 地图
int next_11[2][2] = { {0,1},{1,0} };// 向右和向下
int dp[55][55][15][15];	//动态规划
#define N 1000000007

int dfs(int x, int y, int num,int vmax);

int main11() {
	cin >> n11 >> m11 >> k11;
	for (int i = 0; i < n11; i++)
		for (int j = 0; j < m11; j++)
			cin >> map11[i][j];
	memset(dp, -1, sizeof(dp));
	int a = dfs(0, 0, 0, 0);			// 第一个宝物不拿
	int b = dfs(0, 0, 1, map11[0][0]);	//第一个宝物拿
	cout << (a + b) % N << endl;
	return 0;
}
int dfs(int x, int y, int num,int vmax) {
	if (dp[x][y][num][vmax] != -1)// 如果走过这条路径
		return dp[x][y][num][vmax];
	if ((x == n11 - 1) && (y == m11 - 1)) {// 到达终点
		if (num == k11) {
			dp[x][y][num][vmax] = 1;
			return 1;			// 此方案有效
		}
		else {
			dp[x][y][num][vmax] = 0;
			return 0;			// 此方案无效
		}
	}
	long long fangan = 0;	// 方案数
	for (int i = 0; i < 2; i++) {// 所有邻点
		int x_next = x + next_11[i][0];
		int y_next = y + next_11[i][1];
		if (x_next < n11&&x_next >= 0 && y_next < m11&&y_next >= 0) {// 在地图范围内
			if (vmax < map11[x_next][y_next])// 符合要求
				fangan += dfs(x_next, y_next, num + 1, map11[x_next][y_next]);// 拿
			fangan += dfs(x_next, y_next, num, vmax);// 不拿
		}
	}
	fangan %= N;
	dp[x][y][num][vmax] = fangan;	//保存结果
	return fangan;
}

