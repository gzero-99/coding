

//15649 n과 m c++
#include <iostream>
using namespace std;

int arr[10];
bool check[10];
void make(int idx, int n, int m) {

	//인덱스가 m번째가 되면 출력하기.
	if (idx == m) {
		for (int i = 0; i < m; i++) {//m길이 수열
			cout << arr[i];
			if (i!= m - 1)cout << ' '; //숫자와숫자 사이에 공백출력
		}
		cout << '\n';
		return; //탈출
	}
	//숫자는 1~n을 사용 
	for (int i = 1; i <= n; i++) {
		if (check[i] == true) continue; //이미 사용한 숫자

		//새 숫자면 체크하고
		check[i] = true; 
		arr[idx] = i; //arr 배열에 숫자를 추가
		make(idx + 1, n, m); //arr 다음인덱스에 숫자를 추가하기위해 돌림
		check[i] = false; // 다시 체크제거
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	make(0, n, m);
	return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//뽑은 숫자들을 배열에 저장하고 , 알고리즘에 돌린다.
//순열 알고리즘 
void Permutation(vector<int>& Array, int Start, int End)
{
	if (Start == End)
	{
		for (const auto it : Array)
		{
			cout << it << " ";
		}
		cout << endl;


	}
	else
	{
		for (int i = Start; i <= End; ++i)
		{
			swap(Array[Start], Array[i]);
			Permutation(Array, Start + 1, End);
			swap(Array[Start], Array[i]);
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	//int num[9];
	//for (int i = 1; i <= n; i++) {
	//	num[i] = i;
	//}//1~n까지 저장
	int num[] = {1,2,3,4,5,6,7,8}; 
	vector <int> arr;
	set <int> numArr;
	//m개 뽑기
	for (int i = 0; i < n; i++) {
		arr.push_back(num[i]);
	}
	while (m > 0) {

		m--;
	}
	Permutation(arr, 0, n-1);
	return 0;
}
*/