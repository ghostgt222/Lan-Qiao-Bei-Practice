/*
题目描述
	给定一个n*m的矩阵A，求A中的一个非空子矩阵，使这个子矩阵中的元素和最大。

	其中，A的子矩阵指在A中行和列均连续的一块。

样例说明
	取最后一列，和为10。
	数据规模和约定
	对于100%的数据，1< =n,  m< =500，A中每个元素的绝对值不超过5000。

输入
	输入的第一行包含两个整数n,  m，分别表示矩阵A的行数和列数。
	接下来n行，每行m个整数，表示矩阵A。
输出
	输出一行，包含一个整数，表示A中最大的子矩阵中的元素和。
样例输入
	3  3
	-1  -4  3
	3  4  -1
	-5  -2  8
样例输出
	10
*/

// 行的前缀和（对行区间求和） + 最大子段原理 （对列区间求和）
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	long int xsum[502][502]; //xsum[i][j]前 i 行 j列的前缀和
	int n, m;
	long long int ans, sum = 0;
	memset(xsum, 0, sizeof(xsum));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int temp;
			cin >> temp;
			xsum[i][j] = temp + xsum[i - 1][j]; //xsum[i][j]前 i 行 j列的前缀和
		}
	for (int i = 1; i <= n; i++) //	遍历
		for (int j = i; j <= n; j++) {
			ans = 0;
			for (int k = 1; k <= m; k++) {
				ans += xsum[j][k] - xsum[i - 1][k];
				if (ans > sum || sum == 0)
					sum = ans; //先判断，防止全为负数情况，更新最大值
				if (ans < 0)	// 最大子段原理
					ans = 0;
			}
		}
	cout << sum << endl;
	return 0;
}

#if 0
//********动态规划超内存*********
#include<iostream>
#include<cstring>
using namespace std;

int n18, m18;
int mat18[510][510];
//int dp[500][500][500][500];	// 动态规划

int allchoice18();	// 遍历所有可能
int sum18(int x, int y, int len, int board);	// 求和（起点坐标和长宽）

int main18() {
	cin >> n18 >> m18;
	for (int i = 0; i < n18; i++)
		for (int j = 0; j < m18; j++)
			cin >> mat18[i][j];

	int max = allchoice18();
	cout << max << endl;
	return 0;
}
int allchoice18() {
	int max = mat18[0][0];	// 最大值
	int temp;
	// 遍历
	for (int x = 0; x < n18; x++)
		for (int y = 0; y < m18; y++)
			for (int len = 0; len < m18 - y; len++)
				for (int board = 0; board < n18 - x; board++) {
					temp = sum18(x, y, len, board);
					if (temp > max)	// 比较
						max = temp;
				}
	return max;
}
int sum18(int x, int y, int len, int board) {
	if (len < 0 || board < 0)	// 不符合要求
		return 0;
	//if (dp[x][y][len][board] != 0)	// 动态规划
	//	return dp[x][y][len][board];
	if (len == 0 && board == 0)	// 中止条件
		return mat18[x][y];
	int all = 0;	// 总数
	// 将矩阵切成4份
	all += mat18[x][y];
	all += sum18(x + 1, y + 1, len - 1, board - 1);
	all += sum18(x + 1, y, 0, board - 1);
	all += sum18(x, y + 1, len - 1, 0);
	//dp[x][y][len][board] = all;	// 储存结果
	return all;
}
#endif