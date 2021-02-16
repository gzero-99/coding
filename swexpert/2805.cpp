//[sw] 2805 ���۹� ��Ȯ�ϱ� c++ 
#include <stdio.h>
int main() {
	int TC, N;
	int farm[50][50];
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		int r = 0;
		scanf("%d",&N);
		//������ ���۹� �Է¹ޱ� 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				scanf("%1d", &farm[i][j]);

		//���� ���� ����ϱ�  -  ������ ���
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
		//���� ����ϱ�
		printf("#%d %d", tc, r);
	}
	return 0;
}