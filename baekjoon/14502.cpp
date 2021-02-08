//[����] #14502 ������ �ʺ�켱Ž��BFS
#include <stdio.h>
#include <queue>
using namespace std;
int N, M;
int lab[8][8];
int lab2[8][8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int mx = 0; //0�� �ִ� ����

typedef struct {
	int x;
	int y;
}virus;
queue <virus> q;

//���̷��� ��Ʈ���� 
void bfs() {

	int lab3[8][8];
	for (int a = 0; a < N; a++)
		for (int b = 0; b < M; b++) {
			lab3[a][b] = lab2[a][b];
			if (lab3[a][b] == 2)
				q.push({ a,b });
		}

	while (!q.empty()) {
		//2�� ���̷����� ť���� ã�ƿ�.
		int x = q.front().x;
		int y = q.front().y;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
				//2�� 0�� ������ 2�� ����
				if (lab3[xx][yy] == 0) {
					lab3[xx][yy] = 2;
					q.push({ xx, yy });//2�̹Ƿ� �ٽ� ť�� �߰�
				}
			}
		}
	}
	//queue�� ���� (���̷��� ��Ʈ��) 0�� ������ Ȯ���ؼ� 
	//�ִ� ���� ������ �ִ� ũ�� ���(���� ū 0�� ����)
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab3[i][j] == 0) {
				cnt++;
			}
		}
	}
	mx = mx > cnt ? mx : cnt;

	return;
}

void make_wall(int wall) {
	if (wall == 3)
	{//�� 3�� �������Ƿ� ���̷��� ��Ʈ����
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//���� ����� �������� ��ĭ�̸�
			if (lab2[i][j] == 0) {
				lab2[i][j] = 1;//�������
				make_wall(wall + 1); //���� �� �����
				lab2[i][j] = 0;//���㹰��
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);//3<=N,M<=8

						   //�������� ũ�� ��ŭ �Է�
						   //��ĭ 0 ���� 1 ���̷��� 2
						   //2�� ������ 2���� ũ�ų� ����, 10���� �۰ų� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 2) {
				//printf("%d ", lab[i][j]);
				q.push({ i, j });
			}
		}
	}

	//���� �� 3���� ���� �� ����.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//��ĭ�̸� �� ����� ����
			if (lab[i][j] == 0) {
				//���� �ѹ�
				for (int a = 0; a < N; a++)
					for (int b = 0; b < M; b++)
						lab2[a][b] = lab[a][b];
				lab2[i][j] = 1;//�� �����
				make_wall(1);//1�� �� ����
				lab2[i][j] = 0;//�� �㹰��
			}
		}
	}
	printf("%d", mx);

	return 0;
}
