
//[백준] #10773 제로 c++
//스택 이용 풀이
#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack <int >s;
	int k,n,  num=0;
	cin >> k;

	while (k > 0) {
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
		k--;
	}

	if (s.empty())
		num = 0;
	else {
		int size = s.size();
		for (int i = 1; i <= size; i++) {
			num += s.top();
			s.pop();
		}
	}
	cout << num;
	return 0;
}
