#include <iostream>
using namespace std;

void f(int& x, int& y){
	x = 1;
	y = 3;
}

int main(int argc, char *argv[]) {
	int* A = new int[2];
	A[0] = 0;
	A[1] = 2;
	f(A[0], A[A[0]]);
	cout << "A[0]: " << A[0] << ", A[1]: " << A[1] << endl;
	return 0;
}

