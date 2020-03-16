#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include<time.h>
using namespace std;

const int MAXN = 200020;
int nums[MAXN];

// �Զ�����������������ֵ�Ӵ�С���� 
bool com(int a, int b);
void I();

int maini() {
	clock_t startTime, endTime;
	startTime = clock();
	I();
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
	return 0;
}

bool com(int a, int b) {
	return abs(a) > abs(b);
}

void I() {
	int N, M;
	cin >> N >> M;
	int n = N + M + 1;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", nums + i);
	}
	sort(nums, nums + n, com);
	// ������������� 
	for (int i = 0; i < n && M > 0; i++) {
		if (nums[i] < 0) {
			nums[i] = -nums[i];
			M--;
		}
	}
	// ��������ڸ��ţ����������ֱ�ɸ��� 
	if (M) {
		for (int i = n - M; i < n; i++) {
			nums[i] = -nums[i];
		}
	}
	// ��� 
	for (int i = 0; i < n; i++) {
		res += nums[i];
	}
	cout << res << endl;
}