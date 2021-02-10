//[백준] #10026 적록색약
#include <iostream>
#include <queue>
using namespace std;
int N;
int color[100][100];
int area[100][100];
bool checked[100][100];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

typedef struct {
	int x;
	int y;
}red;
queue<red>q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
				if (color[xx][yy] == 0) {
					color[xx][yy] = 1;
					q.push({ xx,yy });
				}
			}
		}
	}
}
void dfs(int x, int y,int cnt) {
	if (checked[x][y] == false)checked[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
		if (checked[xx][yy] == true)continue;

		if (color[x][y] == color[xx][yy]) {
			checked[xx][yy] = true;
			area[xx][yy] = cnt;
			dfs(xx, yy, cnt);
		}
	}
}
int main() {
	cin >> N;
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			if (c == 'R') {
				color[i][j] = 1;
				q.push({ i,j });
			}
			else if (c == 'G')color[i][j] = 0;
			//(적록색약은)1이 0을 만나면 1되도록 ..해줄것임
			else color[i][j] = 2;
		}
	}

	//적록색약이 아닌 사람이 봤을때 구역의 수 ..
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			if (checked[i][j] == false) {
				cnt++;
				area[i][j] = cnt;
				dfs(i, j, cnt);
			}
		}
	}
	cout << cnt << " ";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			checked[i][j] = false; //초기화
			area[i][j] = 0;
		}
	}
	//적록색약인 사람이 봤을때 구역의 수 ..
	cnt = 0;
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (checked[i][j] == false) {
				cnt++;
				area[i][j] = cnt;
				dfs(i, j, cnt);
			}
		}
	}
	cout << cnt << endl;

	return 0;
}

/*
//연습출력1
cout << endl;
for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
		cout << color[i][j] << " ";
	}
	cout << endl;
}
for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
		cout << area[i][j] << " ";
	}
	cout << endl;
}
*/
/*
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N;
int color[100][100];

int clcnt[100][100];
int wecnt[100][100];
int cnt;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

typedef struct {
	int x;
	int y;
}red;
queue<red>q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
				if (color[xx][yy] == 0) {
					color[xx][yy] = 1;
					q.push({ xx,yy });
				}
			}
		}
	}
}

int main() {
	cin >> N;
	string str;

	for (int i = 0; i < N; i++){
		cin >> str;
		int j = 0;
		for (string::iterator iter = str.begin(); iter != str.end(); ++iter) {
			j++;
			if (*iter == 'R') {
				color[i][j] = 1;
				q.push({ i,j });
				//weak[i][j] = true;
			}
			else if (*iter == 'G') {
				color[i][j] = 0;
				//weak[i][j] = true;
			}
			//(적록색약은)1이 0을 만나면 1되도록 ..해줄것임
			else { 
				color[i][j] = 2;
				//weak[i][j] = false;
			}

		}
	}
	//적록색약이 아닌 사람이 봤을때 구역의 수 ..

	//적록색약인 사람이 봤을때 구역의 수 ..


	return 0;
}
*/