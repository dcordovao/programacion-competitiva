#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n;
long int xi,vi,max_x,min_x,max_dis,min_v=1000000000,X[500000],V[500000];
bool posible,possitive;
bool colission(double time){
    double maxi=-10000000000;
    double pos;
    for (int i=0;i<n;i++){
        pos = X[i]+time*V[i];
        if (V[i]>0){
            if (pos>maxi){
                maxi = pos;
            }
        }
        else {
            if (pos<=maxi) return true;
        }

    }
    return false;
}

double bs(){
    double time,bottom, top,past_time=-1;
    top = ((double)max_dis/(double)min_v);
    bottom=0;

    while (top-bottom>0.0000000000001){
        time = (top+bottom)/2.0;
        if (time == past_time) break;
        if (colission(time)){
            top=time;
        }
        else {
            bottom = time;
        }
        past_time = time;
    }
    return time;
}

int main()
{
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%li %li",&xi,&vi);
        X[i]=xi;
        V[i]=vi;
        if (vi>0) possitive=true;
        if (vi<0 && possitive) posible=true;
        if (abs(vi)<min_v) min_v=abs(vi);
        if (xi>max_x) max_x=xi;
        if (xi<min_x) min_x=xi;
    }
    max_dis=max_x-min_x;
    if (posible) printf ("%.20f",bs());
    else printf("-1");
    return 0;
}
