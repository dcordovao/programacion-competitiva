// String Taks 118A

#include <iostream>
#include <string>

using namespace std;

int main(){
	int i;
	char l;
	string input;
	cin >> input;
	for (i=0;i<input.length();i++){
		l=input[i];
		if (l!='a' && l!='e' && l!='i' && l!='o' && l!='u' && l!='y' && l!='A' && l!='E' && l!='I' && l!='O' && l!='U' && l!='Y'){
			cout << ".";
			if (l>=65 && l<=90) l = l+32;
			cout << l;
		}
	}
	return 0;
}
