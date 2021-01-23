// #1074 c++ z [bj] gzero ��
#include <iostream>
#define MAX 32770 // 2^15 = 32768
using namespace std;
int N, r, c; //2^N x 2^N array ( r row , c column ) :  explore in Z order 
int rst;

//���� ������ �迭�� ��������� �ʾƵ��� 
void zExplore(int x, int y, int n) {
	if (r == x && c == y) {// (r,c)ã���� ��� ���
		cout << rst;
		return;
	}
	//N=3�̸�,
	//0 <= r < 8 �� 0 <= c < 8 
	
	//x <= r < x+n	�� y <= c < y+n 
	if (r < x + n && r >= x && c < y + n && c >= y)//���� ��и鿡 (r,c)�� ���ϸ�
	{
		//�״��� ���� ��и���� �����ش�. 8x8���ٸ� 4x4�� z�������
		zExplore(x, y, n / 2); // 1��и�
		zExplore(x, y + n / 2, n / 2);//2��и�
		zExplore(x + n / 2, y, n / 2); //3��и�
		zExplore(x + n / 2, y + n / 2, n / 2); //4��и�
	}

	//���� ��и��� �ƴϸ�, �� ���� ��и��� ũ��(�湮�������ϴϱ�) ������.
	else rst += n * n; 
	

}

int main() {
	cin >> N >> r >> c;
	//N= 3 , 8x8 -> 4x4 -> 2x2 
	//use divide and conquer && recursion 
	zExplore(0, 0,1<<N); 
	// *** 0001 <<N : �������� N��ŭ ��Ʈ �̵�. / 1�� N���� 0��Ʈ
	//N=3 �̸� 1000 == 8

	return 0;
}
//1��и�
// 0 ,0 ->//���� 1��и� 0,1 -> 1,0 -> 1,1 //�� 1��и� 
// 0,2 -> 0,3 -> 1,2 -> 1,3 
// 2,0 -> 2,1 -> 3,0 -> 3,1
// 2,2 -> 2,3 -> 3, 2 -> 3,3

//2��и�
// 0,4 -> 0,5 -> 1,4 -> 1,5 
// 0,6 -> 0,7 -> 1,6 -> 1,7
// 2,4 -> 2,5 -> 3, 4 -> 3, 5
// 2,6 -> 2,7 -> 3,6 -> 3,7