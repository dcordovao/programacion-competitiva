#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{

    long long n,i,c;
    char last;
    bool condition1=0, condition2=0;
    set <long long> position11,position00;
    set <long long>::iterator it;

    string chain;
    cin >> n;
    cin >> chain;
    last = chain[0];
    c=1;

    for (i=0;i<n;i++)
    {
        /* Contador */
        if (i!=0)
        {
            if (chain[i]!= last) c++;
            last = chain[i];
        }

        if (i<n-1)
        {

            if (!condition2)
            {
                if (chain[i]=='1' && chain[i+1]=='1')
                {
                    condition1 =1;
                    if (!position00.empty()) condition2=1;
                    position11.insert(i);
                    for (it=position11.begin();it!=position11.end();it++)
                    {
                        if (*it<i)
                        {
                            condition2=1;
                            break;
                        }
                    }
                }

                if (chain[i]=='0' && chain[i+1]=='0')
                {
                    condition1=1;
                    if (!position11.empty()) condition2=1;
                    position00.insert(i);
                    for (it=position00.begin();it!=position00.end();it++)
                    {
                        if (*it<i)
                        {
                            condition2=1;
                            break;
                        }
                    }
                }

            }
        }

    }
    if (condition2) cout << c+2;
    else if (condition1) cout << c+1;
    else cout << c;


    return 0;
}
