#include <cstdio>

using namespace std;

int main(){
    int n,i,j,aux,prom=0,arr[101];
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%d",&aux);
        arr[i]=aux;
        prom+=aux;
    }
    prom =(2*prom)/n;
    for (i=1;i<=n;i++){
        if (arr[i]!=-1){
            for (j=i+1;j<=n;j++){
                if (arr[j]+arr[i]==prom){
                    printf ("%d %d\n",i,j);
                    arr[i]=-1;
                    arr[j]=-1;
                    break;
                }
            }
        }
    }
}
