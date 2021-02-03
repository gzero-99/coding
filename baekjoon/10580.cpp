
//전봇대 성공! 
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int TC, N, a, b;

	vector <int> A;
	vector <int> B;
	scanf("%d", &TC);

	int  tmp = 1, cnt = 0;
	//x좌표는 A끼리 같고 , B끼리 같음 
	while (TC > 0) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &a);
			scanf("%d", &b);
			A.push_back(a); //왼쪽 점들 모임 
			B.push_back(b); //오른쪽 점들 모임 
		}

		printf("#%d ", tmp);

		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (A.at(j) < A.at(k) && B.at(k) < B.at(j))
					cnt += 1;
				else if (A.at(k) < A.at(j) && B.at(j) < B.at(k))
					cnt += 1;
			}
		}

		printf("%d\n", cnt);
		cnt = 0;
		A.clear();
		B.clear();
		tmp++;
		TC--;
	}

	return 0;
}
/*
//전봇대 재도전 ..?
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int TC, N, a, b;
	scanf("%d", &TC);
	int A[1000], B[1000];
	int  tmp = 1, cnt = 0;
	//x좌표는 A끼리 같고 , B끼리 같음 
	while (TC > 0) {
		scanf("%d", &N); 
		
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a); 
			scanf("%d", &b); 
			A[i] = a; //왼쪽 점들 모임 
			B[i] = b; //오른쪽 점들 모임 
		}

		printf("#%d ", tmp);

		for (int j = 0; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				if (A[j] < A[k] && B[k] < B[j])
					cnt += 1;
				else if (A[k] < A[j] && B[j] < B[k])
					cnt += 1;
			}
		}

		printf("%d\n",cnt);
		cnt = 0;
		A.clear();
		B.clear();
		tmp++;
		TC--;
	}

	return 0;
}
*/