//MAGNETS

#include <cstdio>

int main() {
	int n, result = 1, input;

	bool last; //True if last positive.
	scanf("%d", &n);
	scanf("%d", &input);
	if (input == 10)
		last = true;
	else
		last = false;

	for (int i = 1; i < n; i++) {
		scanf("%d", &input);
		if (input == 10) {
			if (!last) result++;
			last = true;
		} else {
			if (last) result++;
			last = false;
		}
	}
	printf("%d\n", result);
}
