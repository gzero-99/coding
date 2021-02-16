//[sw] 2805 농작물 수확하기 c++ 
#include <stdio.h>
int main() {
	int TC, N;
	int farm[50][50];
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		int r = 0;
		scanf("%d",&N);
		//농장의 농작물 입력받기 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				scanf("%1d", &farm[i][j]);

		//농장 수익 계산하기  -  마름모 모양
		int mid = N / 2;
		int left = N / 2;
		int right = N / 2;
		for (int i = 0; i < N; i++) {
			for (int j = left; j <= right; j++) {
				r += farm[i][j];
			}
			if (i < mid) {
				left--;
				right++;
			}
			else {
				left++;
				right--;
			}
		}
		//수익 출력하기
		printf("#%d %d", tc, r);
	}
	return 0;
}