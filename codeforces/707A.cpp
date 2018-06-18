#include <iostream>

using namespace std;

int main (){
	int n,m,i,j;
	bool color = false;
	char pixel;
	cin >> n >> m;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			cin >> pixel;
			if (pixel == 'C' || pixel == 'M' || pixel == 'Y'){
				color = true;
			}
		}
	}
	if (color) cout << "#Color\n";
	else cout << "#Black&White\n";
	return 0;
}
