//[bj] #1365 꼬인전깃줄 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int main() {
	int N;
	cin >> N;
	int num;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (v.empty() || v.back() < num)
			v.push_back(num);
		else {
			cnt++;
			auto iter = lower_bound(v.begin(), v.end(), num);
			*iter = num;
			//수열의 마지막보다 값이 작으면, lower_bound를 찾는다
			//범위에 삽입된 값 num보다 크거나 같은 첫 원소의 iterator를 반환한다.
		}
	}
	cout << cnt;
	return 0;
}