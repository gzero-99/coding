
//������ [sw] 2819 �������� �����̾� ���̱� �� c++ 
//dfs�� �Ű������� Ȱ���ؼ� �Ѱ��ֱ� .
#include <stdio.h>
#include <set>
#include <math.h>
using namespace std;
int grid[5][5]; //������
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
		
		//�� ���� �͵��̸� ,, 
		gxy = grid[xx][yy];
		if (cnt < 7) {		
			// 7�ڸ� ���� �ɶ�����.
			dfs_recursion(xx, yy ,gxy*int(pow(10,cnt))+ num, cnt+1); // ���
		}
		// ������x,y ���� ������ dfs����
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
	for (int i = 1; i <= T; i++) //TC���� �ݺ�.
	{
		//1. ���ڿ� ���� �Է¹ޱ� 
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				scanf_s("%d", &grid[j][k]);

		//2. 2���� �迭���� ��������� ��� ���
		// 6�� �����̰�, set�� �����ϱ� ( �ߺ��� �˾Ƽ� �ɷ��� ) 
		for (int j = 1; j <= 4; j++) 
			for (int k = 1; k <= 4; k++) {
				printf("j: %d , k: %d\n", j, k);
				dfs_recursion(j, k , grid[j][k],1);
			}

		//3. set size ����ϸ� �� .
		printf("#%d %d\n", i, sevenNum.size());

		//4.set �ʱ�ȭ �����ֱ�.
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
int grid[5][5]; //������
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

		//�� ���� �͵��̸� ,, 
		if (cnt <= 7) {
			cnt++;
			str7 += grid[xx][yy]; // ���ڿ��� ���� ���̱�
			std::cout << str7;
			dfs_recursion(xx, yy); // ���
		}
		// ������x,y ���� ������ dfs����
		else if (cnt > 7) { 
			seven.insert(str7);
			return;
		}
	}
	

}
int main() {
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++) //TC���� �ݺ�.
	{
		//1. ���ڿ� ���� �Է¹ޱ� 
		for (int j = 1; j <= 4; j++) 
			for (int k = 1; k <= 4; k++) 
				scanf_s("%d", &grid[j][k]);

		//2. 2���� �迭���� ��������� ��� ���
		// 6�� �����̰�, set�� �����ϱ� ( �ߺ��� �˾Ƽ� �ɷ��� ) 
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++) {
				cnt = 1;
				str7 = grid[j][k];
				dfs_recursion(j, k);
			}
	
		//3. set size ����ϸ� �� .
		printf("#%d %d", i ,seven.size()); 
		
		//4.set �ʱ�ȭ �����ֱ�.
		seven.clear();
	}
	return 0;
}
*/