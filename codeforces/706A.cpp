//Codeforces 706A - Beru Taxi

#include <stdio.h>
#include <math.h>

int main(){
	int n,a,b,xi,yi,vi;
	float time, solution = 100000;

	scanf ("%d %d",&a,&b);
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d",&xi,&yi,&vi);
		time = (pow(xi-a,2)+pow(yi-b,2))/(pow(vi,2));
		if (time<solution) solution=time;
	}
	solution = sqrt(solution);
	printf ("%f\n",solution);
}
