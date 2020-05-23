#include <stdio.h>

int x[5][5] = { {0, 1, 2, 0, 0},
				{0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0}};

int main(int argc, char *argv[]) {
	
	int i, j, n = 5;
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (x[i][j] != 0){
				j = n+1;
			}
		}
		if (j > n) continue;
		printf("First all zero row is: %d\n", i);
		break;
	}
	
	
	return 0;
}

