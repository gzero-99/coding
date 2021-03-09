//#12738 가장긴 증가하는 부분수열3 (2와 범위 - 추가된 것 차이)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int main() {
	int N;
	cin >> N;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (v.empty() || v.back() < num)
			v.push_back(num);
		else {
			auto iter = lower_bound(v.begin(), v.end(), num);
			*iter = num;
			//수열의 마지막보다 값이 작으면, lower_bound를 찾는다
			//범위에 삽입된 값 num보다 크거나 같은 첫 원소의 iterator를 반환한다.
		}
	}
	cout << v.size();
	return 0;
}