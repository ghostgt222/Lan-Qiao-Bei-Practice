#include <iostream>
using namespace std;

void funcb(int n) {
	if (!n) {
		return;
	}
	funcb(n / 26);
	cout << (char)(n % 26 + 64);
}

int mainb() {
	funcb(2019);
	return 0;
}