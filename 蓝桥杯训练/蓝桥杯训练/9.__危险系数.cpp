/*
问题描述
    抗日战争时期，冀中平原的地道战曾发挥重要作用。
    地道的多个站点间有通道连接，形成了庞大的网络。但也有隐患，当敌人发现了某个站点后，其它站点间可能因此会失去联系。
    我们来定义一个危险系数DF(x,y)：
    对于两个站点x和y  (x  !=  y),  如果能找到一个站点z，当z被敌人破坏后，x和y不连通，那么我们称z为关于x,y的关键点。相应的，对于任意一对站点x和y，危险系数DF(x,y)就表示为这两点之间的关键点个数。
    本题的任务是：已知网络结构，求两站点之间的危险系数。
输入
    输入数据第一行包含2个整数n(2  < =  n  < =  1000),  m(0  < =  m  < =  2000),分别代表站点数，通道数；
    接下来m行，每行两个整数  u,v  (1  < =  u,  v  < =  n;  u  !=  v)代表一条通道；
    最后1行，两个数u,v，代表询问两点之间的危险系数DF(u,  v)。
输出
    一个整数，如果询问的两点不连通则输出-1.
样例输入
    7  6
    1  3
    2  3
    3  4
    3  5
    4  5
    5  6
    1  6
样例输出
    2
*/

#include<iostream>
using namespace std;

int n9, m9;		// 站点数，通道数
int map9[1001][1001];		// 标记节点间的通道，0代表无，1代表有
int sign9[2000];

int func9(int u, int v);
bool dfs(int u, int v, int i, int *sign);

int main9() {
	cin >> n9 >> m9;
	int u, v;
	for (int i = 0; i < m9; i++) {
		cin >> u >> v;
		map9[u][v] = map9[v][u] = 1;  // 标记通道
	}
	cin >> u >> v;
	cout << func9(u, v) << endl;
	return 0;
}
int func9(int u, int v) {
	int sum = 0;  // 危险系数
	for (int i = 1; i < n9 + 1; i++) {
		if (i != u && i != v) {
			//int sign[n] = new int[n] ;  // 标记灰色节点
			int status1 = dfs(u, v, -1, sign9); //i存在时是否连通
			//int sign2[n] = { 0 };  // 标记灰色节点
			int status2 = dfs(u, v, i, sign9);	//i不存在时是否连通
			if (status1 == 1 && status2 == 0)
				sum++;
		}
	}
	return sum;
}
bool dfs(int u, int v, int i, int *sign) {
	if (map9[u][v] == 1) {
		return true;
	}
	for (int j = 1; j < n9 + 1; j++) {
		if (j != u && j != v && j != i && sign[j] != 1 && map9[u][j] == 1) {// 符合条件的邻点
			sign[j] = 1;
			if (dfs(j, v, i, sign)) {
				sign[j] = 0;
				return true;
			}
			sign[j] = 0;
		}
	}
	return false;
}