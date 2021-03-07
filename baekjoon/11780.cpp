//[백준] #11780 플로이드2 c++

#include <iostream>
#include <string>
#define INF 987654321
#define MIN(a,b) a<b?a:b
using namespace std;
int arr[100][100];	// 도시-도시로 가는데 드는 비용 저장 배열
int path[100][100]; // 최단경로 중 지나는 노드 저장
int between = 0;
string result;
void PrintPath( int start, int end) {
	if (path[start][end] != -1) {
		PrintPath(start, path[start][end ]);
		string s = to_string(path[start][end]+1);
		result.append(s);
		result.append(" ");
		between++;
		//cout << "\nbetween: "<<between << " ";
		PrintPath (path[start][end ], end);
	}
}  

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int A, B, C;
	// 버스시작도시 , 도착도시 , 한번 타는 데 필요비용(자연수<=10000)

	cin >> N;	// 2<=n<=100개 도시 
	cin >> M;	//1<=m<=100,000개 버스

				//정보 입력받기
	int m = 0;	//m개 줄에 버스의 정보 
	while (m < M) {
		m++;
		cin >> A >> B >> C;
		if (arr[A - 1][B - 1] != 0) {//같은 경로면,  더 비용 싼 애 저장
			arr[A - 1][B - 1] = MIN(arr[A - 1][B - 1], C);
		}
		else arr[A - 1][B - 1] = C;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) //갈수없으면
				arr[i][j] = INF; //가장큰수넣기
			path[i][j] = -1;
		}
	}

	//도시의 쌍 (A,B) A->B에 필요한 최소 비용구하기
	//플로이드 - 알고리즘
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
				if (arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
					//중간 경로 저장하기 추가
					path[i][j] = k;
				}
			}
		}

	}

	//i->j 배열출력 && 도시로 갈 수 없는 경우 0 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i == j))	cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}


	//플로이드 2 추가 부분 : i->j 최소비용 경로에 있는 도시 개수 && 도시 경로 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i == j))	cout << 0 << "\n";
			else {
				PrintPath(i, j);
				if (result.compare("")==0)//빈문자열이라면..
					cout << 2 + between << " " << i + 1 << " " << j + 1 << "\n";
				else
					cout << 2 + between << " " << i + 1 << " " + result << j + 1 << "\n";
				between = 0;
				result = "";
			}
		}
	}
	return 0;
}

/*

	//path 출력연습
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			 cout << path[i][j] << " ";
		}
		cout << "\n";
	}
*/