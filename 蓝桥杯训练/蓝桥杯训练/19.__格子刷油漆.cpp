/*
��Ŀ����
	X����һ�ιų�ǽ�Ķ��˿��Կ���  2*N��������ɵľ��Σ�����ͼ��ʾ��������Ҫ����Щ����ˢ�ϱ����ᡣ
	a c e
	b d f
	����Դ�����һ������ˢ��ˢ��һ�񣬿����ƶ����������ڵĸ��ӣ��Խ�����Ҳ���������������ƶ�����Զ�ĸ��ӣ���Ϊ����δ�ɲ��ܲȣ���
	���磺a  d  b  c  e  f  ���Ǻϸ��ˢ��˳��
	c  e  f  d  a  b  ����һ�ֺ��ʵķ�����
	����֪  N  ʱ�����ܵķ���������N�ϴ�ʱ�������Ѹ��������ѽ����  1000000007  (ʮ������)  ȡģ��

����
	��������Ϊһ����������������1000��
���
	�������Ϊһ����������
��������
	3
�������
	96
*/

//************dfs��ʱ***********
#include<iostream>
#include<queue>
using namespace std;

#define MOD19 1000000007
int n19;
int map19[2][1000];
int _next19[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1} };// �˸�����

int dfs19(int x, int y, int deep);

int main19() {
	cin >> n19;
	int sum = 0;
	for (int y = 0; y < n19 / 2; y++) {// ֻ��Ҫ��1/4���ɣ���Ϊ�Գ�
		map19[0][y] = 1;
		sum += dfs19(0, y, 1);
		map19[0][y] = 0;
		sum %= MOD19;
	}
	sum = (sum * 4) % MOD19;
	if (n19 % 2) {// ���n������
		map19[0][n19 / 2] = 1;
		sum += (dfs19(0, n19 / 2, 1)) * 2;
		sum %= MOD19;
	}
	cout << sum << endl;
	return 0;
}

int dfs19(int x, int y, int deep) {
	if (deep == 2 * n19)// ����ȫ��ˢ��
		return 1;
	int sum = 0;
	for (int i = 0; i < 8; i++) {// ��ͬ����dfs
		int x_temp = x + _next19[i][0];
		int y_temp = y + _next19[i][1];
		if (x_temp >= 0 && x_temp < 2 && y_temp >= 0 && y_temp < n19&&map19[x_temp][y_temp] == 0) {// ����Ҫ���·��
			map19[x_temp][y_temp] = 1;	// ����߹� 
			sum += dfs19(x_temp, y_temp, deep + 1);
			map19[x_temp][y_temp] = 0;	// ȥ�����
			sum %= MOD19;
		}
	}
	return sum % MOD19;
}