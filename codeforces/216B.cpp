#include <iostream>

using namespace std;

class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;

		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{
		id[i] = j;
		sz[j] += sz[i];
	} else	{
		id[j] = i;
		sz[i] += sz[j];
	}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};

int main(){
    short aux,i,j,n1,n2,n,m,out=0;
    cin >> n >> m;
    UF enemies(n);
    for (i=0;i<m;i++){
        cin >> n1 >> n2;
        n1--;
        n2--;
        if (enemies.connected(n1,n2))
        {
            aux=0;
            for (j=0;j<n;j++)
            {
                if (enemies.find(j)==enemies.find(n1)) aux++;
            }
            if (aux%2==1) out++;
            enemies.merge(n1,n2);
        }
        else enemies.merge(n1,n2);
    }
    if ((n-out)%2==1) cout << out+1;
    else cout << out;
    return 0;
}
