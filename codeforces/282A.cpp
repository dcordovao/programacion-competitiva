#include <cstdio>
#include <string>

using namespace std;

int main(){
	int n, x = 0;
	string input(3, ' ');
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &input[0]);
		bool plus = false, minus = false;
		for (int j = 0; j < 3; j++) {
			if (input[j] == '+') {
				plus = true;
			}
			if (input[j] == '-') {
				minus = true;
			}
		}
		if (plus) {
			x++;
		}
		if (minus) {
			x--;
		}
	}
	printf("%d\n", x);
	return 0;
}
