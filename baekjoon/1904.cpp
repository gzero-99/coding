
//jiyoung [baekjoon] #1904 01tile c++  ¢¾ -dp
#include <iostream>
using namespace std;
int main() {
	int n = 0;
	cin >> n;

	int bb = 1;
	int b = 2;
	int rst = 0;
	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			rst = (b + bb) % 15746;	
			//% use is important - make it run every time
			bb = b;
			b = rst;
		}
		cout << rst;
	}
	else if (n == 2)cout << 2;
	else if (n == 1)cout << 1;

	return 0;
}



/*
int main() {
	vector <int> dp;
	int n=0;
	cin >> n;
	dp.push_back(0);
	dp.push_back(1);
	dp.push_back(2);
	if (n >= 3) {
		int cnt = 3;
		while (cnt <=n) {
			dp.push_back(dp[cnt - 1] + dp[cnt - 2]);
			cnt++;
		}
	}
	int rst = 0;
	rst = dp[n] % 15746;
	cout << rst;
	return 0;
}
*/