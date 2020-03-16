#include <iostream>
#include<time.h>
using namespace std;

void G(int x);

int main3() {
	clock_t startTime, endTime;
	startTime = clock();
	G(10000);
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
	return 0;
}

void G(int x) {

}