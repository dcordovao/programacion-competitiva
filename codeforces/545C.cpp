#include <stdio.h>
#include <map>

using namespace std;

int main()
{

    long int n,i,chopped=1;
    long long xi,hi,xj,hj;
    bool chopLeft=1;

    scanf("%li",&n);
    scanf("%I64d %I64d",&xi,&hi);
    for(i=1;i<n;i++)
    {
        scanf("%I64d %I64d",&xj,&hj);
        if (chopLeft)
        {
            if (xj-hj>xi) chopped++;
            else chopLeft=0;
        }
        else
            if (xi+hi<xj)
            {
                chopped++;
                if (xj-hj>xi+hi)
                {
                    chopped++;
                    chopLeft=1;
                }
            }
            else if (xj-hj>xi)
            {
                chopped++;
                chopLeft=1;
            }
        xi=xj;
        hi=hj;

    }
    if (!chopLeft) chopped++;

    printf ("%li",chopped);
    return 0;
}
