//sw #3752 가능한 시험 점수

#include <iostream>
#include <cstring>
using namespace std;
int N;
int arr[100];
int score[10000]; //0 ~ 10000까지 점수 가능.
int rst;

int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		memset(score, 0, sizeof(score)); //초기화
		rst = 0;
		cin >> N;

		score[0] = true; //0점은 매 경우있음
		int max = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i]; //배점 입력
			max += arr[i]; //만들 수 있는 최대 점수
			for (int j = max; j >= 0; j--) {
				if (score[j]) //j에 해당하는 점수가 있다면 ,
					score[j + arr[i]] = true; //j+현재입력한 배점인 점수도 있도록
			}
			score[arr[i]] = true;//현재 입력한 배점도 점수로 등록
		}
		for (int i = 0; i <= max; i++)//0~최대점수까지
			if (score[i])rst++;//점수가 존재한다면 가능한 점수 경우의 수로 더해줌.

		
		//학생들이 받을 수 있는 점수의 경우의 수 .
		cout << "#" << tc << " " << rst << endl;
	}
	return 0;
}


/*
#include <iostream>
using namespace std;
int N;
int score[100];
int result[100];
bool visited[100];
int rst,cnt;

void count_score(int idx) {
	if (idx >= N) {
		rst++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			result[idx] = score[i];
			visited[i] = true;
			count_score(idx + 1);
			visited[i] = false;
		}
	}
}


int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		rst = 0, cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> score[i];

		count_score(0);
		//학생들이 받을 수 있는 점수의 경우의 수 .
		cout << "#" << tc << " " << rst;
	}
	return 0;
}
*/