<<<<<<< HEAD
//장지영 [sw] d4 동철이의 프로그래밍 대회 ♥
/*
=======
//[sw] #6913 #6958 �룞泥좎씠�쓽 �봽濡쒓렇�옒諛� ����쉶 D4 
>>>>>>> 262bb02a1569fc97786cc490e952a2756954bd29
#include <stdio.h>
int main() {
	int TC, N, M;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d %d", &N,&M);
		int pe_num = 0, pr_num = 0, correct[20];
		for (int n = 0; n < N; n++) {
			int cnt = 0;
			for (int m = 0; m < M; m++) {
				int c; scanf("%d", &c);
				if (c == 1) cnt++; }
			correct[n] = cnt;
			if (pr_num < cnt)pr_num = cnt;
		}
		for (int i = 0; i < N; i++)
			if (correct[i] == pr_num)pe_num++;
		printf("#%d %d %d\n", tc, pe_num, pr_num);
	}
	return 0;
}
<<<<<<< HEAD
*/
=======
>>>>>>> 262bb02a1569fc97786cc490e952a2756954bd29
