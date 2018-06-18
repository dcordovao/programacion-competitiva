#include <iostream>

using namespace std;

int main(){
    int n,i;
    cin >> n;
    for (i=1;i<=n;i++) {
        if (i==n) {
            if (i%2==0) cout << "I love it";
            else cout << "I hate it";
            cout << "\n";
        } else {
            if (i%2==0) cout << "I love that ";
            else cout << "I hate that ";
        }
    }
    return 0;
}
