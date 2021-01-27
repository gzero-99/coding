
//장지영 백준 #5568 카드놓기 c++ ♥
#include <iostream>
#include <set>
#include <string>
using namespace std;
bool check[10];
int card[11]; //n개 카드값 저장 
int num[5]; //k개 카드값 저장 
set <string> s; // 중복 제거하고 정수들 저장해줌 .

				//2,3,4의k가 가능함 
				//k의 경우로 나눠서 set에 저장해주기 .
void make(int idx, int n, int k) {
	if (idx == k) {
		int yet = 0;
		string temp = "";
		for (int i = 0; i < k; i++) {
			string str;
			str = to_string(num[i]);
			temp += str;
		}
		s.insert(temp);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == true) continue; //이미 사용한 숫자	
			check[i] = true;
			num[idx] = card[i]; //num 배열에 숫자를 추가
			make(idx + 1, n, k); //num 다음인덱스에 숫자를 추가하기위해 돌림
			check[i] = false; // 다시 체크제거
		}
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	make(0, n, k);
	cout << s.size();
	return 0;
}


/*
//성공! 출력하는 과정도 있는 버전 
#include <iostream>
#include <set>
#include <string>
using namespace std;
bool check[10];
int card[11]; //n개 카드값 저장 
int num[5]; //k개 카드값 저장 
set <string> s; // 중복 제거하고 정수들 저장해줌 .

			 //2,3,4의k가 가능함 
			 //k의 경우로 나눠서 set에 저장해주기 .
void make(int idx, int n, int k) {

	if (idx == k) {
		int yet = 0;
		string temp="";
		for (int i = 0; i < k; i++) {
			string str;
			str = to_string(num[i]);
			temp += str;
			cout << temp<<" ";
		}
		cout << endl;
		s.insert(temp);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == true) continue; //이미 사용한 숫자	
			check[i] = true;
			num[idx] = card[i]; //num 배열에 숫자를 추가
			make(idx + 1, n, k); //num 다음인덱스에 숫자를 추가하기위해 돌림
			check[i] = false; // 다시 체크제거
		}
	}
}
int main() {
	int n, k;

	cin >> n >> k;
	//n개 카드 값 저장 
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	//n장의 카드에서 k개 뽑기 - 중복없이 출력되도록하기.
	make(0, n, k);
	set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	cout << s.size(); //만들수있는 정수의 개수 출력.

	return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
bool check[10];
int card[11]; //n개 카드값 저장 
int num[5]; //k개 카드값 저장 
set <int> s; // 중복 제거하고 정수들 저장해줌 .

//2,3,4의k가 가능함 
//k의 경우로 나눠서 set에 저장해주기 .
 void make(int idx, int n, int k) {

	 if (idx == k) {
		 int yet = 0;
		 for (int i = 0; i < k; i++) {
			 yet = yet + num[i]*pow(10, k-i-1);
		 }
		 s.insert(yet);
		 return;
	 }
	 else {
		 for (int i = 0; i < n; i++) {
			 if (check[i] == true) continue; //이미 사용한 숫자	
			 check[i] = true;
			 num[idx] = card[i]; //num 배열에 숫자를 추가
			 make(idx + 1, n, k); //num 다음인덱스에 숫자를 추가하기위해 돌림
			 check[i] = false; // 다시 체크제거
		 }
	 }
}
int main() {
	int n, k;

	cin >> n >> k;
	//n개 카드 값 저장 
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	//n장의 카드에서 k개 뽑기 - 중복없이 출력되도록하기.
	make(0, n, k);
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	cout << s.size(); //만들수있는 정수의 개수 출력.
	
	return 0;
}
*/

/*
#include <stdio.h>
#include <set>
using namespace std;
set <int> s;
int n;
int k; // 2<=k<=4
int card[11];//4<=n<=10
int pick[5]; //k크기 배열 - 선택된 카드들이 재저장된다
//k-1개는 고정해둬야함 .. 
//midx 는 k-1 임 .
void card_sel(int sidx, int midx, int eidx ,int pidx) { //카드 k개 선택에 사용 
	//시작 점 , 중간 점, 끝 점
	//고정 단계 
	for (int j = 0; j < k; j++) { //k개 배열 채우기 ..............

	}
	for (int i = sidx; i < midx; i++) {

	}
	
	card_sel(sidx+1, midx, eidx,pidx);

}
void make_num(int cnt) { //k개 카드로 정수 만들기에 사용 

}
int main() {

	scanf_s("%d", &n);
	scanf_s("%d", &k);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &card[i]);
	}

	//1. k개 카드를 선택한다

	//2. 선택한 k개의 카드들을 정수로 조합한다.
	//k크기 배열에 선택한 수들을 저장한다.

	//3. 정수로 조합해 set에 저장한다.

	//4.set은 중복 저장이 되지 않으므로, 상근이가 만들 수 있는 정수의 개수 출력가능 
	printf("%d", s.size());
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
vector <string> v;
set <string> s;
int n;
int k;
//int card[11];
string card[11];

void makeNum( int idx1 , int idx2, int cnt) {

	for (int i = 0; i < n; i++) {
		v.push_back(card[i]);
		makeNum(idx1 + 1, idx2, cnt);
	}
}
int main() {
	int num[5]; //k사이즈만큼.
	cin >> n;//scanf_s("%d", &n); //4<= n <=10
	cin >> k;//scanf_s("%d", &k);  //2<=k<=4
	for (int i = 0; i < n; i++) {
		//scanf("%d", &card[i]);//1<=card에 적힌 정수<=99
		cin >> card[i];
	}

	return 0;
} 
*/

/*
void swap(int idx1, int idx2) {
	int tmp = card[idx1];
	card[idx1] = card[idx2];
	card[idx2] = tmp;
}*/
/*
void makeNum(int idx,int cnt , int num[]) {
	if (cnt == k) {
		for (int i = 0; i < k; i++)
			s.insert(num[i]);
		return;
	}
	for (int i = 0; i < cnt; i++) {
		//
	}
}*/

	
	
	/*
	//중복을 허용하지 않는 순열
	[0	1	2	3]
	1, 2 , 12, 1
	(1) 1, 2 선택 [0,1]-> 1+2 ,2+1 
	(2) 1, 12 선택 [0,2]-> 1+12 , 1+21
	(3) 1, 1 선택 [0,3] -> 1+1 ,1+1 
	(4) 2, 12 선택 [1,2]-> 2+12, 12+2
	(5) 2, 1 선택 [1,3]-> 2+1 , 1+2
	(6) 12, 1 선택  [2,3] ->12+1, 1+12
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){ 
		....
		}
	}
	선택은 그냥 idx돌려주면 되고 ,,?
	선택은 6번 하고 , 숫자 조합 만든느 거는 ...
	선택한 숫자들 개수(k) 만큼을 또 조합해서 set에 저장해주면 됨 
	조합하는게 -> 중복을 허용하지 않는 순열임 ..?

	같은 숫자 조합 제외하고는 , 총 7개 
	*/
