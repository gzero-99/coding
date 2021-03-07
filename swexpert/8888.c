//[sw] 8888 시험 c

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
		//입력받기 &&  푼 문제수 저장
		for (int n = 1; n <= N; n++) {//참가자수1~N
			int cnt = 0;
			test_rank[n] = 1; //등수 초기화
			for (int t = 1; t <= T; t++) {//문제번호1~T
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
			result[n][0] = cnt; //참가자 당 푼 문제수  저장. result [n번 참가자][0] = 푼 문제수
		}
		//같은 j,다른 i의 0 개수를 점수 배열에 저장 
		for (int j = 1; j <= T; j++) {
			int cnt = 0;
			for (int i = 1; i <= N; i++) {
				if (arr[i][j] == 0)
					cnt += 1;
			}
			score[j] = cnt; //문제 당 계산 점수 저장
		}

		//각 참가자의점수 결과 계산 저장 
		for (int i = 1; i <= N; i++) {//참가자별 
			int scr = 0;
			for (int j = 1; j <= T; j++) { //맞은 문제확인
				if (arr[i][j] == 1) //맞으면 해당 문제의 점수를 더해줌 .
					scr += score[j];
			}
			result[i][1] = scr; // result [n번 참가자][1]=계산된 점수 저장
		}
		//등수 계산 (점수결과 ->푼 문제수 -> (점수와 문제수 동일하면) 앞순서의 참가자가 높은 등수)
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
		//P번 참가자인 지학이의 점수와 등수 출력하기
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

/*//입력값예제
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