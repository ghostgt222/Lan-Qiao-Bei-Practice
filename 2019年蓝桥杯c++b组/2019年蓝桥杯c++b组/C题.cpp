#include <iostream>
using namespace std;

int funcC(int n) {
	if (n <= 3) {
		return 1;
	}
	int a = 1, b = 1, c = 1, res;
	for (int i = 4; i <= n; i++) {
		// 这里要记得取余
		res = (a + b + c) % 10000;
		a = b;
		b = c;
		c = res;
	}
	return res;
}

int mainc() {
	cout << funcC(20190324) << endl;
	return 0;
}