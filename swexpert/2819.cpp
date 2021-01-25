
//장지영 [sw] 2819 격자판의 숫자이어 붙이기 ♥ c++ 
//dfs는 매개변수로 활용해서 넘겨주기 .
#include <stdio.h>
#include <set>
#include <math.h>
using namespace std;
int grid[5][5]; //격자판
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
set <int> sevenNum;
void dfs_recursion(int x, int y, int num, int cnt) {
	int xx, yy;
	int gxy ;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx < 1 || xx>4 || yy < 1 || yy>4)continue;
		
		//그 안의 것들이면 ,, 
		gxy = grid[xx][yy];
		if (cnt < 7) {		
			// 7자리 숫자 될때까지.
			dfs_recursion(xx, yy ,gxy*int(pow(10,cnt))+ num, cnt+1); // 재귀
		}
		// 임의의x,y 에서 시작한 dfs종료
		else if (cnt == 7) {
			printf("%d\n", num);
			sevenNum.insert(num);
			return;
		}
	}
}
int main() {
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++) //TC마다 반복.
	{
		//1. 격자에 숫자 입력받기 
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				scanf_s("%d", &grid[j][k]);

		//2. 2차원 배열에서 만들어지는 모든 경로
		// 6번 움직이고, set에 저장하기 ( 중복은 알아서 걸러짐 ) 
		for (int j = 1; j <= 4; j++) 
			for (int k = 1; k <= 4; k++) {
				printf("j: %d , k: %d\n", j, k);
				dfs_recursion(j, k , grid[j][k],1);
			}

		//3. set size 출력하면 됨 .
		printf("#%d %d\n", i, sevenNum.size());

		//4.set 초기화 시켜주기.
		sevenNum.clear();
	}
	return 0;
}


/*
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int grid[5][5]; //격자판
set <string> seven;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
string str7;
int cnt = 0;
void dfs_recursion(int x, int y) {
	int xx, yy;

	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx < 1 || xx>4 || yy < 1 || yy>4)continue;

		//그 안의 것들이면 ,, 
		if (cnt <= 7) {
			cnt++;
			str7 += grid[xx][yy]; // 문자열에 숫자 붙이기
			std::cout << str7;
			dfs_recursion(xx, yy); // 재귀
		}
		// 임의의x,y 에서 시작한 dfs종료
		else if (cnt > 7) { 
			seven.insert(str7);
			return;
		}
	}
	

}
int main() {
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++) //TC마다 반복.
	{
		//1. 격자에 숫자 입력받기 
		for (int j = 1; j <= 4; j++) 
			for (int k = 1; k <= 4; k++) 
				scanf_s("%d", &grid[j][k]);

		//2. 2차원 배열에서 만들어지는 모든 경로
		// 6번 움직이고, set에 저장하기 ( 중복은 알아서 걸러짐 ) 
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++) {
				cnt = 1;
				str7 = grid[j][k];
				dfs_recursion(j, k);
			}
	
		//3. set size 출력하면 됨 .
		printf("#%d %d", i ,seven.size()); 
		
		//4.set 초기화 시켜주기.
		seven.clear();
	}
	return 0;
}
*/