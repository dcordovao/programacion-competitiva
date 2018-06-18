#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int n,q,xi,i,bot,top;
long qi;
int shops[100000];
long money[100000];

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int binary_search(long mon){
	int bot,top,middle;
	bot=0;
	top=n-1;
	while (abs(top-bot)>1){
		middle= (top+bot)/2;
		if (shops[middle]<=mon) bot = middle;
		else top = middle;
	}
	if (shops[top]<=mon) return top;
	else if (shops[bot]<=mon) return bot;
	else return -1;
}

int main(){

	scanf("%d",&n);
	i=0;
	while (i<n){
		scanf("%d",&shops[i]);
		i++;
	}
	qsort(shops, n, sizeof(int), cmpfunc);
	scanf("%d",&q);
	while (q--){
		scanf("%li",&qi);
		printf ("%d\n",binary_search(qi)+1);
	}
	return 0;
}
