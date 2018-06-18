#include <iostream>
#include <vector>

using namespace std;

int main(){
    short n,x,aux,cont,i;
    vector <bool> arr;
    cin >> n ;
    arr = vector<bool>(n+1,false);
    cont=0;
    i=2;
    while (i--){
        cin >> x;
        while (x--){
            cin >> aux;
            if (!arr[aux]){
                cont++;
                arr[aux]=true;
            }
        }
    }
    if (cont==n) cout << "I become the guy." << endl;
    else cout << "Oh, my keyboard!" << endl;
    return 0;
}
