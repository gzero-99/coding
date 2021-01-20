//장지영 [백준] #2156 포도주 시식 c++ ♥
#include <iostream>
#define MAXNUM 10002
#define MAXOF3(a,b,c) a<b?(b<c?c:b):(a<c?c:a)
using namespace std;

int main() {
	int n;
	int wine[MAXNUM];
	int dp[MAXNUM];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	int res = 0;
	int cnt = 3;
	if (n == 1)
		res = wine[1];
	else if (n == 2)
		res = wine[1] + wine[2];
	else {
		dp[0] = 0;
		dp[1] = wine[1];
		dp[2] = wine[1] + wine[2];
		while (cnt <= n) {
			//[]x , []x0 , []x00 선택은 2개까지만 가능하고 , 1개 이상 선택안하기 가능   
			dp[cnt] = MAXOF3(dp[cnt - 1], dp[cnt - 2] + wine[cnt], dp[cnt - 3] + wine[cnt - 1] + wine[cnt]);
			cnt++;
		}
		res = dp[n];
	}
	cout << res;
	return 0;
}


/*
6
8
9
2
1
15
14

6
6
10
13
9
8
1
*/
/*

//결과 나오는데 틀렸습니다,
//이 코드의 반례 : 8 9 2 1 15 14 처럼 2칸(2 1)선택 안하고 89 1514 선택한 경우.
//장지영 [백준] #2156 포도주 시식 c++
#include <iostream>
#define MAXNUM 10002
#define MAX(a,b,c) a<b?(b<c?c:b):(a<c?c:a)
using namespace std;
int n;
int wine[MAXNUM];
int memo1[MAXNUM];
int memo2[MAXNUM];
int memo3[MAXNUM];
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	int res = 0;
	int cnt = 3;
	if (n == 1)
		res = wine[1];
	else if (n == 2)
		res = wine[1] + wine[2];
	else {
		while (cnt <= n) {
			if (cnt == 3) {
				memo1[cnt] = wine[1] + wine[2];
				memo2[cnt] = wine[2] + wine[3];
				memo3[cnt] = wine[1] + wine[3];
				cout << "cnt: " << cnt << ", memo1: " << memo1[cnt];
				cout << " memo2: " << memo2[cnt];
				cout << " memo3: " << memo3[cnt] << endl;
			}
			else if(cnt%3 ==1){
				memo1[cnt] = memo1[cnt - 1] + wine[cnt];
				memo2[cnt] = memo2[cnt - 1];
				memo3[cnt] = memo3[cnt - 1] + wine[cnt];
				cout << "cnt: "<< cnt<<", memo1: " << memo1[cnt];
				cout << " memo3: " << memo3[cnt] << endl;
			}
			else if (cnt % 3 == 2) {
				memo1[cnt] = memo1[cnt - 1] + wine[cnt];
				memo2[cnt] = memo2[cnt - 1] + wine[cnt];
				memo3[cnt] = memo3[cnt - 1];

				cout << "cnt: " << cnt << ", memo1: " << memo1[cnt];
				cout << " memo2: " << memo2[cnt] << endl;
			}
			else if (cnt % 3 == 0) {
				memo1[cnt] = memo1[cnt - 1];
				memo2[cnt] = memo2[cnt - 1] + wine[cnt];
				memo3[cnt] = memo3[cnt - 1] + wine[cnt];
				cout << "cnt: " << cnt << ", memo2: " << memo2[cnt];
				cout << " memo3: " << memo3[cnt] << endl;
			}
			cnt++;
		}
		res = MAX(memo1[n], memo2[n], memo3[n]);
	}

	cout << res;
	return 0;
}
*/