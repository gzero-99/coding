//[백준] #7569 토마토(3차원)  
#include <iostream>
#include <queue>
#include <cstdio>
#define MAX 101
using namespace std;
int N, M, H;
int box[MAX][MAX][MAX];
int days[MAX][MAX][MAX];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

int main() {
	cin >> M >> N >> H;
	queue<pair <pair<int, int>, int>> q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[i][j][k];
				days[i][j][k] = -1;//초기화
				//익은 토마토 ->큐에넣기
				if (box[i][j][k] == 1) {
					q.push(make_pair(make_pair(i, j), k));
					days[i][j][k] = 0;
				}
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int zz = z + dz[i];

			if (xx < 0 || yy < 0 || zz < 0 ||
				xx >= N || yy >= M || zz >= H)continue;

			//익지 않고, 방문아직 안한 토마토라면?
			if (box[xx][yy][zz] == 0 && days[xx][yy][zz] == -1) {
				q.push(make_pair(make_pair(xx, yy), zz));
				days[xx][yy][zz] = days[x][y][z] + 1;
			}
		}
	}

	int rst = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j][k] == 0 && days[i][j][k] == -1) {
					cout << "-1" << endl;
					return 0;
				}
				if (rst < days[i][j][k]) {
					rst = days[i][j][k];
				}
			}
		}
	}

	cout << rst;
	return 0;
}