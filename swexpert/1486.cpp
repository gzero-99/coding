//#1486 [sw] 장훈이의 높은 선반 
#include <iostream>
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;
int H[20];

int main() {
	int TC, N, B;
	cin >> TC, N, B;

	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> B;
		for (int i = 0; i < N; i++)
			cin >> H[i];

		//N개 비트 00001->00010->00011->...검사하기
		int sum, mi = 200000; //20만이 최대
		for (int check = 1; check < (1 << N); check++) {
			sum = 0;
			/*
			비트마스크쓴거 그럼 2중 포문이니까
			현재 ch가 0101일때,
			두번쨰 포문 들어가면
			0번 비트에서 N번 비트까지 확인하는데
			0번 비트 1 / 1번 비트 0 / 2번비트 1
			곧 H[0]과 H[2] 을 sum에 더해준다는 !! 형식!
			*/

			//원소의 포함 여부 확인 -> 비트가 켜져있으면 더해주자.
			for (int i = 0; i < N; i++) 
				if (check&(1 << i)) 
					sum += H[i];


			//합계가 B보다 높으면 차이 확인
			if (sum > B)
				mi = MIN(mi, sum - B);//차이가 더 작은 놈 저장
			//합계가 목표랑 같으면 그냥 break :0이 최소 차이이므로
			if (sum == B)
			{
				mi = 0;
				break;
			}
		}
		cout << "#" << tc << " " << mi << endl;
	}
	return 0;
}



//(6/10실패)
/*
#include <iostream>
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;

int N, B, rst;
int H[20];
bool flag[20];
int smallest = -1;

void smaller(int sum) {
	if (sum < B) return;
	else if (sum >= B) { // B선반높이보다 크고,
		if (smallest<B)  //현재 가장작은 높이가 B보다 작으면
			smallest = sum;
		else rst = MIN(smallest, sum);
	}
}

void C(int n, int r) {
	if (n == r) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (flag[i] == 1)
				sum += H[i];
		}
		for (int i = 0; i < n; i++) {
			flag[i] = 0;
		}

		smaller(sum);
		return;
	}
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (flag[j] == 1)
					sum += H[j];
			}
			flag[i] = 0;
			smaller(sum);
		}

		return;
	}
	flag[n - 1] = 1;
	C(n - 1, r - 1);
	flag[n - 1] = 0;
	C(n - 1, r);
}
int main() {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {

		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i]; //점원의 키 입력받기
		}

		for (int j = 0; j < N; j++) {
			C(N, j + 1);//조합 구하기
		}
		cout << "#" << tc << " " << rst - B << endl;
	}
	return 0;
}
*/


/*
//주석 버전
#include <iostream>
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;

int N, B, rst;
int H[20];
bool flag[20];
int min = -1;

void smaller(int sum) {
	if (sum < B) {
		return;
	}
	else if (sum >= B) { // B선반높이보다 크고,
		if (min<B) { //현재 가장작은 높이가 B보다 작으면
			min = sum;
			//cout << "3" << endl;
			//cout << "min: " << sum << endl;
		}
		else {
			rst = MIN(min, sum);
			//cout << "4" << endl;
			//cout << "rst: " << rst << endl;
		}
	}
}

void C(int n, int r) {
	if (n == r) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (flag[i] == 1)
				sum += H[i];
		}
		//cout << "2" << endl;
		//cout << "sum: " << sum << endl;
		for (int i = 0; i < n; i++) {
			flag[i] = 0;
		}
		
		smaller(sum);
		return;
	}
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (flag[j] == 1)
					sum += H[j];
			}
			//cout << "1" << endl;
			//cout << "sum: " << sum << endl;
			flag[i] = 0;
			smaller(sum);
		}
		
		return;
	}
	flag[n - 1] = 1;
	C(n - 1, r - 1);
	flag[n - 1] = 0;
	C(n - 1, r);
}
int main() {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {

		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i]; //점원의 키 입력받기
		} 

		for (int j = 0; j < N; j++) {
			 C(N, j+1);
		}
		cout << "#" << tc << " " << rst - B << endl;
	}
	return 0;
}
*/


/*
//실패 .. 
#include <iostream>
#define INF 987654321
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;
int N, B, rst;
int H[20];//20명의 점원까지 가능.

void clerk_top(int s, int idx) {

	if (idx >= N) {
		if (s < B)return; //B보다 작으면 안됨

		int min = s - B;

		//if()
	}
	//결론적으로 직원들의 탑이 최소보다 크면 종료..
	if (s >= rst) return;

	//직원들의 탑이 선반보다 크면?
	else if (idx >= N) {
		if (s >= B && s < rst)
			rst = s;
		return;
	}

	//직원들 조합 
	else {
		//idx번 점원 키 더하지 않음
		clerk_top(idx + 1, s);
		
		//idx번 점원 키 더함
		clerk_top(idx + 1, s + H[idx]);
	}

} 

int main() {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {

		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i]; //점원의 키 입력받기
		}

		rst = INF; //일단 큰 값 넣어줌.
		clerk_top(0, 0);
		//int min = rst - B;
		//cout << "#" << tc << " " << min << endl;
	}
	return 0;
}
*/