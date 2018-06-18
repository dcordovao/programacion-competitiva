#include <iostream>
#include <algorithm>
using namespace std;

unsigned int arr[100001];

int main()
{
    long long h_max,h_0,h_w;
    long int w_max,m,n,i,aux,wi,hi;
    cin >> n;
    for (i=0;i<n;i++){
        cin >> aux;
        arr[i]=aux;
    }
    cin >> m;
    cin >> wi >> hi;
    w_max=wi;
    h_0= arr[0];
    h_w= arr[wi-1];
    if (h_0>=h_w){
        cout << h_0 << endl;
        h_max=h_0+hi;
    }
    else {
        cout << h_w << endl;
        h_max=h_w+hi;
    }
    for (i=1;i<m;i++){
        cin >> wi >> hi;
        if (w_max>=wi) {
            w_max=wi;
            cout << h_max << endl;
            h_max +=hi;
        }
        else {
            h_w = arr[wi-1];
            if (h_max>=h_w){
                cout << h_max << endl;
                h_max+=hi;
            }
            else {
                cout << h_w << endl;
                h_max = h_w+hi;
            }
        }
    }
    return 0;
}
