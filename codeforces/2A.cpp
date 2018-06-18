#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	map<string, int> markboard;
	vector<pair<string, int> > turns;
	vector<string> winners;
	int n, score;
	string name;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> name >> score;
		markboard[name] += score;
		turns.push_back(make_pair(name, markboard[name]));
	}
	int maximum = -10000000;
	map<string, int>::iterator it;
	for (it = markboard.begin(); it != markboard.end(); it++) {
		if (it->second > maximum) {
			maximum = it->second;
			winners.clear();
			winners.push_back(it->first);
		} else if (it->second == maximum) {
			winners.push_back(it->first);
		}
	}

	int minimum = 1000;
	int	minturn;
	string winner;
	for (int i = 0; i < (int)winners.size(); i++) {
		minturn = 1000;
		for (int j = 0; j < (int)turns.size(); j++) {
			if (turns[j].first == winners[i]) {
				if (turns[j].second >= maximum) {
					minturn = j;
					break;
				}
			}
		}
		//cout << "name: " << winners[i] << "    minturn: " << minturn <<  endl;
		if (minturn < minimum) {
			minimum = minturn;
			winner.assign(winners[i]);
		}
	}
	cout << winner << endl;

	return 0;
}
