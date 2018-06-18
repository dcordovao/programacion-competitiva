#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int n, *arr;
	bool posible = false;
	scanf("%d", &n);
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] != 0) posible = true;
	}

	if (!posible) {
		printf("NO\n");
	} else {
		printf("YES\n");
		queue<pair<int, int> > q;
		int k = 0;
		int l = 0;
		int r = 0;
		bool flag;
		if (arr[0] == 0)
			flag = false;
		else
			flag = true;
		for (int i = 1; i < n; i++) {
			if (arr[i] == 0) {
				r++;
			} else {
				if (flag) {
					q.push(make_pair(l,r));
					k++;
					l=i;
					r=i;
				} else {
					r++;
				}
				flag = true;
			}
		}
		q.push(make_pair(l,r));
		k++;
		printf("%d\n",k);
		while (!q.empty()) {
			printf("%d %d\n", q.front().first+1, q.front().second+1);
			q.pop();
		}
	}

	return 0;
}
