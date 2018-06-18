#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int seq[10], fin[10], result[10];
    int n,m, total=0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> fin[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (seq[i] == fin[j]) {
                result[total] = seq[i];
                total++;
            }
        }
    }
    for (int i = 0; i < total; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
