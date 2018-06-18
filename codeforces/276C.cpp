#include <stdio.h>
#include <algorithm>

using namespace std;

bool mayorque (int i,int j) { return (i>j); }

int main()
{
    long long int suma=0 ,*numeros,*veces,*fin,*inicio,aux,n,q,l,r,i;;
    scanf("%I64d %I64d",&n,&q);
    numeros= new long long int[n];
    veces= new long long int[n];
    fin=new long long int[n];
    inicio=new long long int[n];
    for(i=0;i<n;i++)
    {
        veces[i]=0;
        fin[i]=0;
        inicio[i]=0;
    }
    for (i=0;i<n;i++)
    {
        scanf("%I64d",&numeros[i]);
    }
    for (i=0;i<q;i++)
    {
        scanf("%I64d %I64d",&l,&r);
        inicio[l-1]++;
        fin[r-1]++;
    }
    aux=0;
    for (i=0;i<n;i++)
    {
        aux+=inicio[i];
        veces[i]+=aux;
        aux-=fin[i];

    }
    std::sort(numeros,numeros+n);
    std::sort(veces,veces+n);
    i=n-1;
    while(i>-1)
    {
        if(veces[i]==0) break;
        suma+=(numeros[i]*veces[i]);
        i--;
    }
    printf("%I64d",suma);
    return 0;
}
