#include <cstdio>

using namespace std;

int main(){
    short i;
    long int x,ans=0;
    scanf("%li",&x);
    i=5;
    while (i>0){
        ans+=x/i;
        x=x%i;
        if (x==0) break;
        i--;
    }
    printf ("%li",ans);
    return 0;
}
