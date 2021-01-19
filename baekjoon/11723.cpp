#include <iostream>
#include <string>
using namespace std;

int TC;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> TC;
	int s = 0;
	for (int i = 0; i < TC; i++) {
		
		string str;
		int x;
		cin >> str;
		if (str.compare("add") == 0) {
			cin >> x;
			s |= (1 << x);
		}
		else if (str.compare("remove") == 0) {
			cin >> x;
			s &= ~(1 << x);
		}
		else if (str.compare("check") == 0) { //결과 출력 
			cin >> x;
			if (s&(1 << x))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str.compare("toggle") == 0) {
			cin >> x;
			if (s&(1 << x))
				s &= ~(1 << x);
			else
				s |= (1 << x);
		}
		else if (str.compare("all") == 0) {
			s = (1 << 21) - 1;
		}
		else if (str.compare("empty") == 0) {
			s = 0;
		}
		
	}
	return 0;
}