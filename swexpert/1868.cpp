//[sw] ������ #1868 �������� ����ã�� c++ ��
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
	bomb[x][y] = -1; //�湮�ϸ� -1�� �ٲ��ش�.
	checked[x][y] = 1;
	for (int i = 0; i< 8; i++) {//8������ �� Ȯ���Ѵ�
		xx = x + dx[i];
		yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
		if (checked[xx][yy] == 1)continue;

		
		if (bomb[xx][yy] == 0) { //������ 0�� ������ �ٽ� dfs������. 
			bomb[xx][yy] = -1;	//�� 0�� -1�� �ٲ��ش�.
			lookforbomb(xx, yy);
		}
		bomb[xx][yy] = -1; // 1�� �ֵ� -1�� �ٲ� �� �ֵ���.. 
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
				else { //��ź
					bomb[n][k] = -1;
					checked[n][k] = 1;
				}
				k++;
			}
		}		
		cout << "checked ����ϱ�" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << checked[i][j] << " ";
			}
			cout << endl;
		}

		cout << "bomb ����ϱ�" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << bomb[i][j] << " ";
			}
			cout << endl;
		}

		//0�ֺ��� ��ź �ִ��� Ȯ��. ������ 1�� �ٲ�����.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] == 0) {
					for (int k = 0; k < 8; k++) { //8������ �� Ȯ���Ѵ�.
						int xx = i + dx[k];
						int yy = j + dy[k];

						if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;

						if (bomb[xx][yy] == -1)//��ź ������
						{
							bomb[i][j] = 1;
							break;
						}//0�̸鼭 0�ξָ� 0�� / 0������ �ֺ��� ��ź ������ 1
					}
				}
			}
		}
		cout << "checked ����ϱ�" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << checked[i][j] << " ";
			}
			cout << endl;
		}

		cout << "bomb ����ϱ�" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << bomb[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] == 0 ) {//0�ִ� ������ dfs������.
					lookforbomb(i, j);
					cnt++;
					cout << "�߰� cnt: " << cnt << endl;

					//���κ��� ��� ���⿡ ��ź�̾����� �� �ֵ��� ���� 1���� Ŭ������ģ��.
				}
			}
		}
		cout << "checked ����ϱ�" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << checked[i][j] << " ";
			}
			cout << endl;
		}

		cout << "bomb ����ϱ�" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << bomb[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bomb[i][j] >= 0) {//0�ִ� ������ dfs������.
					cnt++;
					cout << "������ cnt: " << cnt << endl;
					//���κ��� ��� ���⿡ ��ź�̾����� �� �ֵ��� ���� 1���� Ŭ������ģ��.
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

cout << "checked ����ϱ�" << endl;
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
cout << checked[i][j] << " ";
}
cout << endl;
}

cout << "bomb ����ϱ�" << endl;
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
cout << bomb[i][j] << " ";
}
cout << endl;
}
*/



/*
//[sw] ������ #1868 �������� ����ã�� c++
//��Ÿ�� ���� ...
#include <iostream>
#include <string>
#define MAX 301
using namespace std;
int TC;
int N, rst = 0;
int cnt = 0;
int nbomb[MAX][MAX];//-1�̶� 0���� ����
int bomb[MAX][MAX];//�ֺ��� ��ź���� �����
bool checked[MAX][MAX];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

void lookfornobomb(int x, int y) {
	int xx, yy;
	int mxy;
	for (int i = 0; i < 8; i++) { //8������ �� Ȯ���Ѵ�.
		xx = x + dx[i];
		yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
		if (checked[xx][yy] == 1)continue;

		if (nbomb[xx][yy] == 0) {
			checked[xx][yy] = 1;
			lookfornobomb(xx, yy);
		}

	}
	if (bomb[x][y]==0) {//��ź�� �����ٸ� ..
		for (int i = 0; i < 8; i++) {
			xx = x + dx[i];
			yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
			if (nbomb[xx][yy] == 0) {
				cout << "��ź������ : " << xx << " ," << yy << endl;
				nbomb[xx][yy] = -1;
				nbomb[x][y] = -1;
			}
		}
		cout << "�Ѱ���" << endl;
		return;
	}
	

	
}
int main() {
	string S;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N; //1<=N<=300 (N*N ǥ)
		//ǥ�� ���ڿ��� �Է¹ޱ�
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
		cout << "nbomb 2���� �迭 ����ϱ�" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << nbomb[p][y] << " ";
			}
			cout << endl;
		}
		cout << "checked 2���� �迭 ����ϱ�" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << checked[p][y] << " ";
			}
			cout << endl;
		}
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				if (nbomb[p][y] == 0) {
					for (int a = 0; a < 8; a++) { //8������ �� Ȯ���Ѵ�.
						int pp = p + dx[a];
						int yy = y + dy[a];

						if (pp < 0 || pp >= N || yy < 0 || yy >= N)continue;
						//if (checked[pp][yy] == true)continue;

						if (nbomb[pp][yy] == -1)//��ź ������
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
				if (nbomb[a][b] == 0 && checked[a][b]==0) {//dfs������.
					lookfornobomb(a, b);
					cnt += 1;//�ٱ� ���� ���κ��� ��� ���⿡ ��ź�̾����� �� �ֵ��� ���� 1���� Ŭ������ģ��.
				}
			}
		}
		cout << "nbomb 2���� �迭 ����ϱ�" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << nbomb[p][y] << " ";
			}
			cout << endl;
		}
		cout << "checked 2���� �迭 ����ϱ�" << endl;
		for (int p = 0; p < N; p++) {
			for (int y = 0; y < N; y++) {
				cout << checked[p][y] << " ";
			}
			cout << endl;
		}
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (nbomb[a][b] == 0) {//0�� ������ �κе��� cnt������ �����ش�.
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

1. ǥ���� 0�� �κ��� ã�� dfs ������
2. dfs�� �����¿츦 �湮�ϰ� ������ �κп� 0�� ������ �ű�� �Ѿ�� �����¿� �����ֱ�
3. �湮�� ���� -1�� ���������
4. ǥ���� ��� 0�� �湮�ߴٸ� �� �κе��� ��� -1�� �Ǿ����� ��
5. �湮���� ���� �������κе��� cnt�� ���� ���������ֱ�
����� dfs �ѹ��� cnt �ϳ�

*/