//[백준] #11403 경로찾기

#include <iostream>
using namespace std;
int N;
bool G[100][100];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> G[i][j]; // 0이면 i->j 간선 없음 , 1이면 i->j 간선 있음.

	for (int k = 0; k < N; k++) { //거쳐가는 노드
		for (int i = 0; i < N; i++) { //출발 노드
			for (int j = 0; j < N; j++) { //도착 노드
				if (G[i][k] == 1 && G[k][j] == 1)
					G[i][j] = 1;
			}
		}
	}
	//출력하기  : 정점i->j 가는 경로가 있다면, i번째 줄의j번째 칸에 1표시.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << G[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}