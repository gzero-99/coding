
#include <stdio.h>
// 다이나믹 프로그래밍
int main() {
	int TC, n;
	int dp[11];

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	scanf("%d", &TC);

	for (int i = 0; i < TC; i++) {
		scanf("%d", &n);
		for (int j = 4; j <= n; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		printf("%d\n", dp[n]);
	}
	return 0;

}

/*
//재귀코드

#include < stdio.h>
int cnt=0;
void add(int sum,int goal){
	if(sum>goal) return;
	else if(sum == goal){
		cnt++;
		return;
	}
	else{
		for(int i=1;i<=3;i++)}
			add(sun+1 ,goal);
		}
	}
}
int main(){
	int tc,n;
	scanf("%d",&tc);
	for(int i=0;i<tc;i++){
		cnt =0;
		add(0,n);
		printf("%d\n",cnt);
	}

	return 0;
}
*/