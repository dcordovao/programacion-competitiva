#include <iostream>  // cin, cout
#include <map>      // map
#include <utility> //pair
using namespace std;

int main()
{
    map <short, pair <short,long> > adList; /* Adjacency list, where the pair holds <end of road,weight> */
    map <short,short> tanks; /* If tanks[i]==1; i has a tank */
    short i,start,finish,actual,n,p,cont=0;
    long diameter,mini;
    pair <int,long> aux;
    cin >> n >> p;
    for (i=0;i<p;i++)
    {
        cin >> start >> finish >> diameter;
        if (tanks[start]!=-1) tanks[start]=1;
        tanks[finish]=-1; /* If a pipe ends in house i, then i is not a tank house */
        aux = make_pair(finish,diameter);
        adList[start] = aux;
    }
    for (i=1;i<=n;i++) if (tanks[i]==1) cont++; /* Counting number of tanks */
    cout << cont << endl;
    for (i=1;i<=n;i++) /* Search tanks and go over the path that starts in each tank */
    {
        if (tanks[i]==1)
        {
            actual=i;
            mini = adList[actual].second;
            actual = adList[actual].first;
            while (adList[actual].first!=0 && adList[actual].second!=0) /*Search minimum pipe until  end of the path */
            {
                if (adList[actual].second<mini) mini=adList[actual].second;
                actual = adList[actual].first;
            }
            cout << i << " " << actual << " " << mini << endl;
        }
    }
    return 0;
}
