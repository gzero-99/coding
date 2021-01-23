// #1074 c++ z [bj] gzero ♥
#include <iostream>
#define MAX 32770 // 2^15 = 32768
using namespace std;
int N, r, c; //2^N x 2^N array ( r row , c column ) :  explore in Z order 
int rst;

//굳이 이차원 배열을 만들어주지 않아도됨 
void zExplore(int x, int y, int n) {
	if (r == x && c == y) {// (r,c)찾으면 결과 출력
		cout << rst;
		return;
	}
	//N=3이면,
	//0 <= r < 8 와 0 <= c < 8 
	
	//x <= r < x+n	와 y <= c < y+n 
	if (r < x + n && r >= x && c < y + n && c >= y)//현재 사분면에 (r,c)가 속하면
	{
		//그다음 작은 사분면들을 돌려준다. 8x8였다면 4x4로 z순서대로
		zExplore(x, y, n / 2); // 1사분면
		zExplore(x, y + n / 2, n / 2);//2사분면
		zExplore(x + n / 2, y, n / 2); //3사분면
		zExplore(x + n / 2, y + n / 2, n / 2); //4사분면
	}

	//현재 사분면이 아니면, 그 앞의 사분면의 크기(방문무조건하니까) 더해줌.
	else rst += n * n; 
	

}

int main() {
	cin >> N >> r >> c;
	//N= 3 , 8x8 -> 4x4 -> 2x2 
	//use divide and conquer && recursion 
	zExplore(0, 0,1<<N); 
	// *** 0001 <<N : 왼쪽으로 N만큼 비트 이동. / 1과 N개의 0비트
	//N=3 이면 1000 == 8

	return 0;
}
//1사분면
// 0 ,0 ->//의의 1사분면 0,1 -> 1,0 -> 1,1 //의 1사분면 
// 0,2 -> 0,3 -> 1,2 -> 1,3 
// 2,0 -> 2,1 -> 3,0 -> 3,1
// 2,2 -> 2,3 -> 3, 2 -> 3,3

//2사분면
// 0,4 -> 0,5 -> 1,4 -> 1,5 
// 0,6 -> 0,7 -> 1,6 -> 1,7
// 2,4 -> 2,5 -> 3, 4 -> 3, 5
// 2,6 -> 2,7 -> 3,6 -> 3,7