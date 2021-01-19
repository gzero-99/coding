//장지영 [백준] #1931 회의실배정 c++ ♥
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int n;
	int x[100001];

	//입력
	cin >> n;
	vector <pair <int, int>> v(n);
	for (int i =0; i <n; i++) {
		cin >> v[i].second; //시작 시간 저장
		cin >> v[i].first; //끝나는 시간 저장
	}

	//제일 빨리 끝나는 강의들 순으로 정렬 - vector사용.
	sort(v.begin() , v.end());

	//그리디
	int cnt = 0;
	x[0] = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= x[cnt] ) { //종료하고 가장 빠른 시작 시간.
			cnt += 1;
			x[cnt] = v[i].first; //종료시간 저장 
			//cout << "종료시간 : " << x[cnt];
		}
	}

	cout << cnt+1;
	return 0;
}


/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

결과는 4여야 함
*/