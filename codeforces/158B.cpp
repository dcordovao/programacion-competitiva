#include <cstdio>
#include <stack>

using namespace std;

int groups[5];

int main()
{
    int n,i,ans=0;
    short aux;
    scanf("%d",&n);
    for (i=1;i<4;i++){
        groups[i]=0;
    }
    while (n--){
        scanf ("%hi",&aux);
        groups[aux]++;
    }
    ans+= groups[4];
    ans+= groups[3];
    if (groups[1]>=groups[3]) groups[1]-= groups[3];
    else groups[1]=0;
    ans+= groups[2]/2+groups[2]%2;
    if (groups[1]>2*(groups[2]%2)) groups[1]-= 2*(groups[2]%2);
    else (groups[1]=0);
    ans+= groups[1]/4 + (bool)(groups[1]%4);
    printf ("%d",ans);
    return 0;
}
