//[백준] 11404 플로이드 
#include <iostream>
#define INF 987654321
#define MIN(a,b) a<b?a:b
using namespace std;
int arr[100][100];	// 도시-도시로 가는데 드는 비용 저장 배열

int main() {
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
		}
	}

	//도시의 쌍 (A,B) A->B에 필요한 최소 비용구하기
	//플로이드 - 알고리즘
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}

	}

	//i->j 도시로 갈 수 없는 경우 0 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i == j))	cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
/*
//출력연습버전
#include <iostream>
#define INF 987654321
#define MIN(a,b) a<b?a:b
using namespace std;

int arr[100][100];	// 도시-도시로 가는데 드는 비용 저장 배열

int main() {
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
		if (arr[A - 1][B - 1] != 0){//같은 경로면,  더 비용 싼 애 저장
			arr[A - 1][B - 1] = MIN(arr[A - 1][B - 1], C);
		}
		else arr[A - 1][B - 1] = C;
		cout << "m : "<<m<< "  C = "<<arr[A - 1][B - 1]<<endl;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
			if (arr[i][j] == 0) //갈수없으면
				arr[i][j] = INF; //가장큰수넣기

		}
		cout << endl;
	}

	//도시의 쌍 (A,B) A->B에 필요한 최소 비용구하기
	//플로이드 - 알고리즘
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
		
	}

	//i->j 도시로 갈 수 없는 경우 0 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i==j))	cout << 0 << " ";
			else cout << arr[i][j] <<" ";
		}
		cout << "\n";
	}
			
	return 0;
}

*/