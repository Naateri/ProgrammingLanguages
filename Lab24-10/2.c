#include <stdio.h>

int func(int* k){
	*k += 4;
	return 3 * (*k) - 1;
}

int main(int argc, char *argv[]) {
	int i = 10, j = 10, sum1, sum2;
	sum1 = (i/2) + func(&i);
	sum2 = func(&j) + (j/2);
	printf("sum1: %d, sum2: %d\n", sum1, sum2);
	return 0;
}

