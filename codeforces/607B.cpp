#include <cstdio>
#include <algorithm>

#define INF 30000

using namespace std;

int arr[510];
int memory[510][510];

int dp(int i, int j){

	if (memory[i][j]!=INF) return memory[i][j];
	if (j-i==0) {
		memory[i][j]=1;
		return 1;
	}
	if (i>j) {
		return 0;
	}

	memory[i][j]= min (memory[i][j], dp(i+1,j)+1);
	for (int k=i+2;k<=j;k++){
		if (arr[k]==arr[i]){
			memory[i][j]=min(memory[i][j],dp(i+1,k-1)+dp(k+1,j));
		}
	}
	if (arr[i]==arr[i+1]) memory[i][j]=min(memory[i][j],1+dp(i+2,j));

	return memory[i][j];

}

int main(){
	int n,ci,l,r,i,j;
	scanf("%d",&n);
	for (i=0;i<=n;i++){
		for (j=i;j<=n;j++){
			memory[i][j]=INF;
		}
	}
	for (i=0;i<n;i++){
		scanf("%d",&ci);
		arr[i]=ci;
	}
	printf ("%d\n",dp(0,n-1));
	return 0;

}
