#include <iostream>
#include<time.h>
using namespace std;

void J();

int mainj() {
	clock_t startTime, endTime;
	startTime = clock();
	J();
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	getchar();
	return 0;
}

void J() {

}