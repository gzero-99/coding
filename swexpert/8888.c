//[sw] 8888 ���� c

#include <stdio.h>
int N, T, P;
int arr[2001][2001];
int score[2001];
int result[2001][2];
int test_rank[2001];
int x;
int main() {
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d %d %d", &N, &T, &P);
		//�Է¹ޱ� &&  Ǭ ������ ����
		for (int n = 1; n <= N; n++) {//�����ڼ�1~N
			int cnt = 0;
			test_rank[n] = 1; //��� �ʱ�ȭ
			for (int t = 1; t <= T; t++) {//������ȣ1~T
				while (1) {
					x = getchar();
					if (x == '1' || x == '0') {
						if(x=='1')
							cnt += 1;
						arr[n][t] = x - '0';
						break;
					}
				}
			}
			result[n][0] = cnt; //������ �� Ǭ ������  ����. result [n�� ������][0] = Ǭ ������
		}
		//���� j,�ٸ� i�� 0 ������ ���� �迭�� ���� 
		for (int j = 1; j <= T; j++) {
			int cnt = 0;
			for (int i = 1; i <= N; i++) {
				if (arr[i][j] == 0)
					cnt += 1;
			}
			score[j] = cnt; //���� �� ��� ���� ����
		}

		//�� ������������ ��� ��� ���� 
		for (int i = 1; i <= N; i++) {//�����ں� 
			int scr = 0;
			for (int j = 1; j <= T; j++) { //���� ����Ȯ��
				if (arr[i][j] == 1) //������ �ش� ������ ������ ������ .
					scr += score[j];
			}
			result[i][1] = scr; // result [n�� ������][1]=���� ���� ����
		}
		//��� ��� (������� ->Ǭ ������ -> (������ ������ �����ϸ�) �ռ����� �����ڰ� ���� ���)
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (result[i][1] < result[j][1])test_rank[i]++;
				else if (result[i][1] == result[j][1])
				{
					if (result[i][0] < result[j][0])test_rank[i]++;
					else if (result[i][0] == result[j][0]) 
						test_rank[j]++;
					else test_rank[j]++;
				}
				else test_rank[j]++;
			}
		}
		//P�� �������� �������� ������ ��� ����ϱ�
		printf("#%d %d %d\n", tc, result[P][1], test_rank[P]);
	}
	return 0;
}


/*
int cnt;
for (int t = 1; t <= T; t++) {
bool a;
cin >> a;
arr[n][t] = a;
if (a == 0)
cnt += 1;
}
score[n] = cnt;
//result[n][0]
*/

/*//�Է°�����
2
5 3 2
0 0 1
1 1 0
1 0 0
1 1 0
1 1 0
5 4 4
1 0 1 1
0 0 1 1
0 1 1 0
0 1 1 0
1 1 1 1
*/