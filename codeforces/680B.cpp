#include <iostream>

using namespace std;

int main()
{
    bool criminals[100];
    bool input;
    int n,a,i,catched=0;
    cin >> n >> a;
    for (i=0;i<n;i++)
    {
        cin >> input;
        criminals[i]=input;
    }
    for (i=0;i<n;i++)
    {
        if ((a-1+i)<=(n-1) && (a-1-i)>=0)
        {
            if (criminals[a-1-i]==1 && criminals[a-1+i]==1)
            {
                if (i==0) catched++;
                else catched+=2;
            }
        }
        else if ((a-1+i)<=(n-1))
        {
            if (criminals[a-1+i]==1) catched++;
        }
        else if ((a-1-i)>=0)
        {
            if (criminals[a-1-i]==1)catched++;
        }
        else break;

    }
    cout << catched;
    return 0;
}
