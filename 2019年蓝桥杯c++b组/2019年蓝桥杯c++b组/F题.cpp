#include <iostream>
#include<time.h>
using namespace std;

bool judgeF(int n);
void F(int x);

int mainf() {
	clock_t startTime, endTime;
	startTime = clock();
	F(10000);
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
	return 0;
}

bool judgeF(int n) {
	int t;
	while (n) {
		if (((t = n % 10) == 2) || t == 0 || t == 1 || t == 9) {
			return true;
		}
		n /= 10;
	}
	return false;
}
void F(int x) {
	int sum = 0;
	for (int i = 0; i <= x; i++) {
		if (judgeF(i))
			sum += i;
	}
	cout << sum << endl;
}