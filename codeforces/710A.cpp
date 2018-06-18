#include <iostream>

using namespace std;

int main(){
    char input;
    bool border_row = false, border_col=false;
    cin >> input;
    if (input == 'a' || input == 'h')
        border_col = true;
    cin >> input;
    if (input == '1' || input == '8')
        border_row = true;
    if (border_row && border_col)
        cout << "3";
    else if (border_row || border_col)
        cout << "5";
    else
        cout << "8";
    return 0;
}
