#include <iostream>

#include <string>

using namespace std;
int main(){
	int n,i,ans=0;
	string str;
	cin >> n;
	cin >> str;
	for (i=1;i<n;i++){
		if (str[i]==str[i-1]) ans++;
	}
	cout << ans << endl;
	return 0;

}
2
