//[sw] 장지영 #1868 파핑파핑 지뢰찾기 c++ ♥
/*
#include <iostream>
#include <string>
#define MAX 301
using namespace  std;
int TC, N;

int bomb[MAX][MAX];
bool checked[MAX][MAX];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

void lookforbomb(int x, int y) {
	int xx, yy;
	bomb[x][y] = -1; 
	checked[x][y] = 1;
	for (int i = 0; i< 8; i++) {
		xx = x + dx[i];
		yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
		if (checked[xx][yy] == 1)continue;
		if (bomb[xx][yy] == 0) { 
			bomb[xx][yy] = -1;	
			lookforbomb(xx, yy);
		}
		bomb[xx][yy] = -1; 
	}
	return;
}

int main() {
	string S;
	cin >> TC;
	for (int test_case = 1; test_case <= TC; test_case++) {
		int rst = 0, cnt = 0;
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> S;
			int k = 0;
			for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
				if (*iter == '.') {
					bomb[n][k] = 0;
					checked[n][k] = 0;
				}
				else { 
					bomb[n][k] = -1;
					checked[n][k] = 1;
				}
				k++;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] == 0) {
					for (int k = 0; k < 8; k++) { 
						int xx = i + dx[k];
						int yy = j + dy[k];

						if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
						if (bomb[xx][yy] == -1)
						{
							bomb[i][j] = 1;
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] == 0) {
					lookforbomb(i, j);
					cnt++;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] >= 0) {
					cnt++;
				}
			}
		}
		rst = cnt;
		cout << "#" << test_case << " " << rst << "\n";
	}

	return 0;
}
*/
/*
#include <iostream>
#include <string>
#define MAX 301
using namespace  std;
int TC, N;

int bomb[MAX][MAX];
bool checked[MAX][MAX];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

void lookforbomb(int x, int y) {
	int xx, yy;
	bomb[x][y] = -1; //방문하면 -1로 바꿔준다.
	checked[x][y] = 1;
	for (int i = 0; i< 8; i++) {//8방향을 다 확인한다
		xx = x + dx[i];
		yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
		if (checked[xx][yy] == 1)continue;

		
		if (bomb[xx][yy] == 0) { //인접한 0을 만나면 다시 dfs돌려줌. 
			bomb[xx][yy] = -1;	//그 0을 -1로 바꿔준다.
			lookforbomb(xx, yy);
		}
		bomb[xx][yy] = -1; // 1인 애도 -1로 바뀔 수 있도록.. 
	}
	return;
}

int main() {
	string S;
	cin >> TC;
	for (int test_case = 1; test_case <= TC; test_case++) {
		int rst = 0, cnt = 0;
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> S;
			int k = 0;
			for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
				if (*iter == '.') {
					bomb[n][k] = 0;
					checked[n][k] = 0;
				}
				else { //폭탄
					bomb[n][k] = -1;
					checked[n][k] = 1;
				}
				k++;
			}
		}		
		cout << "checked 출력하기" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << checked[i][j] << " ";
			}
			cout << endl;
		}

		cout << "bomb 출력하기" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << bomb[i][j] << " ";
			}
			cout << endl;
		}

		//0주변에 폭탄 있는지 확인. 있으면 1로 바꿔주자.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] == 0) {
					for (int k = 0; k < 8; k++) { //8방향을 다 확인한다.
						int xx = i + dx[k];
						int yy = j + dy[k];

						if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;

						if (bomb[xx][yy] == -1)//폭탄 만나면
						{
							bomb[i][j] = 1;
							break;
						}//0이면서 0인애만 0됨 / 0이지만 주변에 폭탄 있으면 1
					}
				}
			}
		}
		cout << "checked 출력하기" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << checked[i][j] << " ";
			}
			cout << endl;
		}

		cout << "bomb 출력하기" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << bomb[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] == 0 ) {//0있는 곳부터 dfs돌린다.
					lookforbomb(i, j);
					cnt++;
					cout << "중간 cnt: " << cnt << endl;

					//나로부터 모든 방향에 폭탄이없으면 그 애들을 전부 1번의 클릭으로친다.
				}
			}
		}
		cout << "checked 출력하기" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << checked[i][j] << " ";
			}
			cout << endl;
		}

		cout << "bomb 출력하기" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << bomb[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] >= 0) {//0있는 곳부터 dfs돌린다.
					cnt++;
					cout << "마지막 cnt: " << cnt << endl;
					//나로부터 모든 방향에 폭탄이없으면 그 애들을 전부 1번의 클릭으로친다.
				}
			}
		}

		rst = cnt;
		cout << "#" << test_case << " " << rst << "\n";
	}

	return 0;
}
*/
/*

cout << "checked 출력하기" << endl;
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
cout << checked[i][j] << " ";
}
cout << endl;
}

cout << "bomb 출력하기" << endl;
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
cout << bomb[i][j] << " ";
}
cout << endl;
}
*/



/*
//[sw] 장지영 #1868 파핑파핑 지뢰찾기 c++
//런타임 에러 ...
#include <iostream>
#include <string>
#define MAX 301
using namespace std;
int TC;
int N, rst = 0;
int cnt = 0;
int nbomb[MAX][MAX];//-1이랑 0으로 구분
int bomb[MAX][MAX];//주변에 폭탄개수 저장용
bool checked[MAX][MAX];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

void lookfornobomb(int x, int y) {
	int xx, yy;
	int mxy;
	for (int i = 0; i < 8; i++) { //8방향을 다 확인한다.
		xx = x + dx[i];
		yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
		if (checked[xx][yy] == 1)continue;

		if (nbomb[xx][yy] == 0) {
			checked[xx][yy] = 1;
			lookfornobomb(xx, yy);
		}

	}
	if (bomb[x][y]==0) {//폭탄이 없었다면 ..
		for (int i = 0; i < 8; i++) {
			xx = x + dx[i];
			yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
			if (nbomb[xx][yy] == 0) {
				cout << "폭탄없었음 : " << xx << " ," << yy << endl;
				nbomb[xx][yy] = -1;
				nbomb[x][y] = -1;
			}
		}
		cout << "한개끝" << endl;
		return;
	}
	

	
}
int main() {
	string S;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N; //1<=N<=300 (N*N 표)
		//표를 문자열로 입력받기
		for (int j = 0; j < N; j++) {
			cin >> S;
			int k = 0;
			for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
				//char c = *iter;
				if (*iter == '.') {
					nbomb[j][k] = 0;
					checked[j][k] = 0;
					bomb[j][k] = 0; 
				}
				else {
					nbomb[j][k] = -1;
					checked[j][k] = 1;
					bomb[j][k] = 0;
				}
				k++;
			}
		}
		cout << "nbomb 2차원 배열 출력하기" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << nbomb[p][y] << " ";
			}
			cout << endl;
		}
		cout << "checked 2차원 배열 출력하기" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << checked[p][y] << " ";
			}
			cout << endl;
		}
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				if (nbomb[p][y] == 0) {
					for (int a = 0; a < 8; a++) { //8방향을 다 확인한다.
						int pp = p + dx[a];
						int yy = y + dy[a];

						if (pp < 0 || pp >= N || yy < 0 || yy >= N)continue;
						//if (checked[pp][yy] == true)continue;

						if (nbomb[pp][yy] == -1)//폭탄 만나면
						{
							bomb[p][y] = 1;
							break;
						}
					}
				}
			}
		}
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (nbomb[a][b] == 0 && checked[a][b]==0) {//dfs돌린다.
					lookfornobomb(a, b);
					cnt += 1;//바깥 제외 나로부터 모든 방향에 폭탄이없으면 그 애들을 전부 1번의 클릭으로친다.
				}
			}
		}
		cout << "nbomb 2차원 배열 출력하기" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << nbomb[p][y] << " ";
			}
			cout << endl;
		}
		cout << "checked 2차원 배열 출력하기" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << checked[p][y] << " ";
			}
			cout << endl;
		}
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (nbomb[a][b] == 0) {//0인 나머지 부분들을 cnt개수에 더해준다.
					cnt += 1;
				}
			}
		}

		rst = cnt;
		cout << "#" << TC << " " << rst << "\n";
	}
	return 0;
}
*/
/*

1. 표에서 0인 부분을 찾아 dfs 돌리기
2. dfs는 상하좌우를 방문하고 인접한 부분에 0이 있으면 거기로 넘어가서 상하좌우 열어주기
3. 방문한 곳은 -1로 덮어버리기
4. 표에서 모든 0을 방문했다면 그 부분들은 모두 -1이 되어있을 것
5. 방문하지 않은 나머지부분들을 cnt에 전부 개수더해주기
참고로 dfs 한번이 cnt 하나

*/