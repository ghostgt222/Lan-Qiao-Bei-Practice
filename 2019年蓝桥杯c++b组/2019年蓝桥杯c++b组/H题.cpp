#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<time.h>
using namespace std;

int value[100010];
bool mark[100010];

void H();
int gcd(int a, int b);

int mainh() {
	clock_t startTime, endTime;
	startTime = clock();
	H();
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
	return 0;
}


void H() {
	int n, d, len = 0, t;
	int maxx = 0, minn = 0x7fffffff;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		// 保证每个数字只出现一次 
		if (!mark[t]) {
			mark[t] = 1;
			value[len++] = t;
			maxx = max(maxx, t);
			minn = min(minn, t);
		}
	}
	sort(value, value + len);
	if (len <= 1) {
		cout << n << endl;
	}
	else {
		// 求出所有公差的最大公约数 
		d = value[1] - value[0];
		for (int i = 2; i < len; i++) {
			d = gcd(d, value[i] - value[i - 1]);
		}
		cout << ((maxx - minn) / d + 1) << endl;
	}

}

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}