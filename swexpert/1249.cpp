//sw ���޷� 1249 
#include <stdio.h>
#include <queue>
#define INF 987654321
using namespace  std;

int map[101][101];
int time[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	int TC;
	int N;
	queue<pair<int, int>> q;
	scanf("%d", &TC);
		for (int tc = 1; tc <= TC; tc++) {
			scanf("%d", &N); //NxNũ�� ����
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
				time[i][j] = INF;
			}
		}
		//������� 0���� �ʱ�ȭ
		time[0][0] = 0; 
		q.push(make_pair(0, 0));
		while (q.size()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			//�����¿� ������
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;

				if (time[xx][yy] > time[x][y] + map[xx][yy]) {
					time[xx][yy] = time[x][y] + map[xx][yy];
					q.push(make_pair(xx, yy)); // queue�� ���� ��ο���

				}
			}
		}
		//�������� ����� ���
		printf("#%d %d\n", tc, time[N - 1][N - 1]);
	}

}