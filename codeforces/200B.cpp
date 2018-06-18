
#include <iostream>

using namespace std;

int main(){
    int n,i,aux;
    float sum=0;
    cin >> n;
    for (i=0;i<n;i++){
        cin >> aux;
        sum+=(float)aux;
    }
    cout << sum/((float)n) << endl;
    return 0;
}
