//장지영 [백준] #1309 동물원 c++ ♥
#include <stdio.h>
using namespace std;

int main() {
	int N;
	int dp[100002];
	dp[0] = 1;
	dp[1] = 3;
	//dp[2] = 7; dp[3] = 17; dp[4] = 41; 
	scanf_s("%d", &N);
	if (N == 1) {
		printf("%d",dp[1]);
	}
	else {
		for (int i = 2; i <= N; i++) {
			dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
		}
		printf("%d", dp[N]);
	}

	return 0;
}
