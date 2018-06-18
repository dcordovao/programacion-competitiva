#include <cstdio>
#include <vector>

using namespace std;

int main(){
	vector <int> acum_sum(200002, 0);
	int n, k, q;

	scanf("%d %d %d", &n, &k, &q);

	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		acum_sum[l] += 1;
		acum_sum[r+1] -=1;
	}

	vector <int> recom(200001);

	int acum = 0;
	for (int i = 0; i < 200001; i++) {
		acum += acum_sum[i];
		if (acum >= k) {
			recom[i] = 1;
		} else {
			recom[i] = 0;
		}
	}

	acum = 0;
	for (int i = 0; i < 200002; i++) {
		acum += recom[i];
		acum_sum[i] = acum;
	}

	for (int i = 0; i < q; i++) {
		int result = 0, a, b;
		scanf("%d %d", &a, &b);
		result = acum_sum[b]-acum_sum[a-1];
		printf ("%d\n", result);
	}

	return 0;
}
