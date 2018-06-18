#include <cstdio>

int main() {
	char grid[4][4];
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		scanf("%s", grid[i]);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = i-1; k < i+2; k++) {
				for (int l = j-1; l < j+2; l++) {
					int m = 2*i-k;
					int n = 2*j-l;
					if ( k > -1 && k < 4 &&
						l > -1 && l < 4 &&
						m > -1 && m < 4 &&
						n > -1 && n < 4 &&
						(k != i || l != j)) {
							int count = 0;
							int count2 = 0;
							if (grid[i][j] == 'x')
								count++;
							if (grid[k][l] == 'x')
								count++;
							if (grid[m][n] == 'x')
								count++;
							if (grid[i][j] == '.')
								count2++;
							if (grid[k][l] == '.')
								count2++;
							if (grid[m][n] == '.')
								count2++;
							if (count == 2 && count2 ==1)
								flag = true;
					}
				}
			}
		}
	}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
