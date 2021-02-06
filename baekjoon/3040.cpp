//[백준] 백설공주와 일곱 난쟁이 
#include <iostream>
using namespace std;
int num[9];
bool ans[9];//true면 나중에 출력~
int sum, num1, num2;

void find_dwarf() {
	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			//전체합에서 2명값 빼었을 때, 100이 되는 거 찾기
			if (sum - num[i] - num[j] == 100) {
				if (i != j)//그리고 둘이 다른 애면?
				{
					num1 = num[i];
					num2 = num[j];//저장해주기
					return;
				}
			}
		}

	}
}

int main() {
	for (int i= 0; i < 9; i++) {
		cin >> num[i];
		sum += num[i]; //전체합 저장
	}
	find_dwarf();


	//난쟁이 별로 숫자 다 다르다고 했으니,
	for (int i = 0; i < 9; i++) {
		//두개 숫자가 아니라면 출력해줌 ..
		if (num[i] != num1 && num[i] != num2)
			cout << num[i] << endl;
	}
	return 0;
}
/*

각 모자에 100보다 작은 양의 정수 적음
7난쟁이 모자의 숫자의 합이 100되도록 적어둠
아홉 난쟁이에 적힌 모자 주어질때,
난쟁이 찾도록

=> 9개의 수 중 합이 100되는 일곱 개의 수 찾기

입력 1<=N<=99 자연수 9개 줄에
다 다른 수
답이 유일하도록 주어짐

*/
