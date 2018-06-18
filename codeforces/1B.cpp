#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool isdigit(char ch)
{
	if ( ch >= 48 && ch <= 57)
		return true;
	else
		return false;
}

bool iscapital(char ch)
{
	if ( ch >= 65 && ch <= 90 )
		return true;
	else
		return false;
}

int power1 (int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if ((y % 2) == 0)
        return power1 (x, y / 2) * power1 (x, y / 2);
    else
        return x * power1 (x, y / 2) * power1 (x, y / 2);

}

int main()
{
	int n, row, col, cindex, numberindex;
	string input;
	cin >> n;
	cin.ignore(256, '\n'); // to use getline
	while(n--){
		getline(cin, input);
		bool type1 = true; // type1 A2. type2 R2C1

		//admit capital letter
		int i = 0;
		while (i < (int)input.size()) {
			if (isdigit(input[i])) {
				numberindex = i;
				break;
			}
			i++;
		}
		while (i < (int)input.size()) {
			if (iscapital(input[i])) {
				type1 = false;
				break;
			}
			i++;
		}
		//extracting
		if (type1) {
			i = 0;
			row = 0;
			col = 0;
			while (i < (int)input.size()) {
				if (isdigit(input[i]))
					break;
				col += (input[i]-64)*power1(26, (unsigned int)numberindex-i-1); // A is the number 65 in the ASCII table.
				i++;
			}
			while (i < (int)input.size()) {
				row += (input[i]-48)*power1(10, (unsigned int)((int)(input.size())-1-i));
				i++;
			}
			cout << "R" << row << "C" << col << endl;
		} else {
			row = 0;
			col = 0;
			for (i = 0; i < (int)input.size(); i++) {
				if (input[i] == 'C') {
					cindex = i;
					break;
				}
			}
			for (i = 1; i < cindex; i++) {
				row += (input[i]-48)*power1(10, (unsigned int)(cindex-1-i));
			}
			for (i = cindex+1; i < (int)input.size(); i++) {
				col += (input[i]-48)*power1(10, (unsigned int)((int)(input.size())-1-i));
			}
			string strcol = "";
			while (col > 26) {
				if (col%26 == 0) {
					strcol.insert(0, string(1,(char)(26+64)));
					col--;
					col = col/26;
				} else {
					strcol.insert(0, string(1,(char)(col%26+64)));
					col = col/26;
				}
			}
			strcol.insert(0, string(1, (char)(col+64)));
			cout << strcol << row << endl;
		}
	}
	return 0;
}
