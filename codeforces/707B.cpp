#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <limits>

using namespace std;

long n,m,k,u,v,ai,current,node,i;
long long l,weight,answer,infinite;

vector <bool> visited;
vector <long long> dis;
vector <vector<pair <long,long long> > > adlist;

set <pair <long long,long > > priority;
set <pair <long long,long> >::iterator itset;

int main(){
	scanf("%li %li %li",&n,&m,&k);
	infinite=numeric_limits<long long>::max();
	visited = vector <bool>(n+1,false);
	adlist = vector<vector<pair <long,long long> > >(n+1);
	dis = vector<long long>(n+1,infinite);
	while(m--){
		scanf ("%li %li %I64d",&u,&v,&l);
		adlist[u].push_back(make_pair(v,l));
		adlist[v].push_back(make_pair(u,l));
	}
	while (k--){
		scanf("%li",&ai);
		dis[ai]=0;
		priority.insert(make_pair(0,ai));
	}
	while (!priority.empty()){
		itset = priority.begin();
		current = (*itset).second;
		visited[current]=true;
		for (i=0; i<adlist[current].size() ; i++){
			node = adlist[current][i].first;
			weight = adlist[current][i].second;
			if (!visited[node] && dis[node]>dis[current]+weight){
				dis[node]=dis[current]+weight;
				priority.insert(make_pair(dis[node],node));
			}
		}
		priority.erase(itset);
	}
	answer = infinite;
	for (i=1;i<=n;i++){
		if (dis[i]>0 && dis[i]<answer) answer = dis[i];
	}
	if (answer==infinite) printf ("-1\n");
	else printf("%I64d\n",answer);
	return 0;
}
