#include <cstdio>

using namespace std;

int main(){
    long long answer;
    int n,m,i,row,col,rest,rows_attacked=0,colums_attacked=0;
    bool colums[100001], rows[100001];

    scanf ("%d %d",&n,&m);
    answer = ((long long)n)*((long long)n);
    for (i=1;i<=n;i++){
        rows[i]=false;
        colums[i]=false;
    }
    for (i=0;i<m;i++){
        scanf ("%d %d",&row,&col);
        if ( (!rows[row]) && (!colums[col]) ){
            rest=2*n-rows_attacked-colums_attacked-1;
            rows_attacked++;
            colums_attacked++;

        }
        else if( (!rows[row]) || (!colums[col]) ){
            if (!rows[row]){
                rest = n-colums_attacked;
                rows_attacked++;

            }
            else if (!colums[col]){
                rest = n-rows_attacked;
                colums_attacked++;
            }
        }
        else rest=0;
        answer-=rest;
        rows[row]=true;
        colums[col]=true;
        printf (" %I64d\n",answer);
    }
}
