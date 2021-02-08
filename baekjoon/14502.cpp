//[백준] #14502 연구소 너비우선탐색BFS
#include <stdio.h>
#include <queue>
using namespace std;
int N, M;
int lab[8][8];
int lab2[8][8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int mx = 0; //0의 최대 개수

typedef struct {
	int x;
	int y;
}virus;
queue <virus> q;

//바이러스 퍼트리기 
void bfs() {

	int lab3[8][8];
	for (int a = 0; a < N; a++)
		for (int b = 0; b < M; b++) {
			lab3[a][b] = lab2[a][b];
			if (lab3[a][b] == 2)
				q.push({ a,b });
		}

	while (!q.empty()) {
		//2인 바이러스들 큐에서 찾아옴.
		int x = q.front().x;
		int y = q.front().y;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
				//2가 0을 만나면 2로 변경
				if (lab3[xx][yy] == 0) {
					lab3[xx][yy] = 2;
					q.push({ xx, yy });//2이므로 다시 큐에 추가
				}
			}
		}
	}
	//queue다 돌면 (바이러스 퍼트림) 0의 개수를 확인해서 
	//최대 안전 영역의 최대 크기 출력(제일 큰 0의 개수)
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab3[i][j] == 0) {
				cnt++;
			}
		}
	}
	mx = mx > cnt ? mx : cnt;

	return;
}

void make_wall(int wall) {
	if (wall == 3)
	{//벽 3개 세웠으므로 바이러스 퍼트리기
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//현재 복사된 정보에서 빈칸이면
			if (lab2[i][j] == 0) {
				lab2[i][j] = 1;//벽세우기
				make_wall(wall + 1); //다음 벽 세우기
				lab2[i][j] = 0;//벽허물기
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);//3<=N,M<=8

						   //연구소의 크기 만큼 입력
						   //빈칸 0 벽은 1 바이러스 2
						   //2의 개수는 2보다 크거나 같고, 10보다 작거나 같음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 2) {
				//printf("%d ", lab[i][j]);
				q.push({ i, j });
			}
		}
	}

	//벽은 총 3개만 세울 수 있음.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//빈칸이면 벽 세우기 가능
			if (lab[i][j] == 0) {
				//복사 한번
				for (int a = 0; a < N; a++)
					for (int b = 0; b < M; b++)
						lab2[a][b] = lab[a][b];
				lab2[i][j] = 1;//벽 세우기
				make_wall(1);//1개 벽 세움
				lab2[i][j] = 0;//벽 허물기
			}
		}
	}
	printf("%d", mx);

	return 0;
}
