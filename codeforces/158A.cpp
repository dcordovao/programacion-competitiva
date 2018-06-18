// Problem: Next Round 158A

#include <iostream>

using namespace std;

int main()
{
	short i,n,k,a,arr[50];
	cin >> n >> k;
	for (i=0;i<n;i++){
		cin >> a;
		arr[i]=a;
	}
	k = arr[k-1];
	a=0; //Used now as counter
	for (i=0;i<n;i++){
		if (arr[i]>=k && arr[i]>0) a++;
	}
	cout << a << endl;
	ret
