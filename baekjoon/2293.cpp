//장지영 [백준 ] #2293 동전1 c++ ♥
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001]; // 전역변수로 하면 0으로 기본 초기화 되어있음.

int main() {
	int n, k;
	cin >> n >> k;
	int coin[101];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n ); // 동전 크기순으로 나열

	if (k == 1) {
		cout << 1;
	}
	else {
		dp[0] = 1; // 기본 1
 
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				dp[j] += dp[j - coin[i]]; // 다른 액수의 동전으로 바꿀수있으므로 빼줌
			}
		}
		cout << dp[k];
	}
	return 0;
}

/