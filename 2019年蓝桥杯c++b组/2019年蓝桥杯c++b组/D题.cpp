#include<iostream>
#include<time.h>
using namespace std;

int funcD(int x);
int judgeD(int num);

int maind() {
	clock_t startTime, endTime;
	startTime = clock();
	int num = funcD(2019);
	cout << num << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
	return 0;
}

int funcD(int x) {
	int count = 0;
	for (int i = 1; i < x / 3; i++) {
		if (judgeD(i) != 1)
			continue;
		for (int j = i + 1; j < x / 2; j++) {
			int k = 2019 - i - j;
			if (judgeD(j) && judgeD(k) && k > j)
				count++;
		}
	}
	return count;
}
int judgeD(int num) {
	char a, b, c, d;
	a = num % 10;
	b = num / 10 % 10;
	c = num / 100 % 10;
	d = num / 1000;
	if (a == 2 || a == 4 || b == 2 || b == 4 || c == 2 || c == 4 || d == 2 || d == 4) {
		return 0;
	}
	return 1;
}
