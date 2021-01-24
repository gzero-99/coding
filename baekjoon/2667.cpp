
//������ #2667 ���� ������ȣ ���̱� c++ ��
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[26][26]; // 5<=n<=25��
bool checked[26][26];
int danji[626]; // 25*25 �� �ִ��� 
int scnt;
int n;
void find_danji_ofhome(int x, int y, int dcnt, int hcnt) {
	int xx, yy;
	int gxy;

	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (scnt > hcnt) { //���� ���� ū �ŷ� �־��ֱ�,
			hcnt = scnt;
		}
		danji[dcnt] = hcnt; //�߿�
		if (xx < 0 || xx > n - 1 || yy < 0 || yy > n - 1)continue;
		if (checked[xx][yy] == true) continue;

		
		//�����¿� �̵��� ĭ�� ����� ������ ?
		gxy = arr[xx][yy];
		checked[xx][yy] = true;
		if (gxy == 0 && i == 3) { //�����¿� �� ����, 0�̸�  �̵� �׸� ..
			return;
		}
		else if (gxy == 1) {
			scnt = hcnt + 1;
			find_danji_ofhome(xx, yy, dcnt, hcnt + 1);
		}  
	}
}

int main() {
	int dcnt = 0;// ����idx +1 ���ٶ� ���.
	scanf_s("%d", &n);

	//1. ������ �� �Է¹ޱ� (���� ���� ������ �Է�)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			scanf_s("%1d", &arr[i][j]);

	//2. 2���� �迭�� ����� �� �߿���,
	//1�� ������ �ʰ� �̾����� ��� �ϳ��� ������ ������ش�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checked[i][j] == false) { 
				checked[i][j] = true;

				if (arr[i][j] == 0) //0�̸� checked�ϰ� �Ѿ
					continue;
				else if (arr[i][j] == 1) {
					//3. 1�̸� ���� Ž�� ����! 
					dcnt += 1;
					find_danji_ofhome(i, j, dcnt, 1);
					scnt = 0;
				}
			}
			else  continue;
		}
	}

	//4.������� ����ϱ� ���� sort��Ŵ
	int size = sizeof(danji) / sizeof(danji[0]);
	sort(danji, danji + size);

	printf("%d\n", dcnt);
	//5. ����� ���� �迭�� sort���Ѽ� ������ ���ϴ� ���� ���� �����
	for (int i = 0; i < size; i++) {
		if (danji[i] != 0) {
			printf("%d\n", danji[i]);
		}
	}
	return 0;
}


/*
// ���� ����ߴ�!! 
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[26][26]; // 5<=n<=25��
bool checked[26][26];
int danji[626]; // 25*25 �� �ִ��� 
//int homes = 0;
int scnt;
int n;
// 1�� �������� �����ְ�, ���� ���� ������ �� ã�������� ������ .
void find_danji_ofhome(int x,int y, int dcnt, int hcnt) {
	int xx, yy;
	int gxy;
	
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (scnt > hcnt) {
			hcnt = scnt;
		}
		if (xx < 0 || xx > n-1 || yy < 0 || yy > n-1)continue;
		if (checked[xx][yy] == true) continue;
		//�����¿� �̵��� ĭ�� ����� ������ ?
		//�̵��� ���� �迭��
		gxy = arr[xx][yy];
		checked[xx][yy] = true;
		if (gxy == 0 && i ==3) { //0�̸� �����¿� �̵� �׸� ..
			printf("0���� => (%d, %d) �����¿�ٺ���,�̵��׸� hcnt:%d \n", xx, yy,hcnt);
			return;
		}
		else if (gxy == 0) {
			printf("0���� => (%d, %d) �̵��׸� \n", xx, yy);
		}
		else if (gxy == 1) {
			printf("1���� => (%d, %d) %d ������: %d ��° ��\n",xx,yy,dcnt,hcnt+1);
			scnt = hcnt + 1;
			danji[dcnt] = hcnt + 1;
			find_danji_ofhome(xx,yy,dcnt, hcnt+1 );
			
		}
	}
}

int main() {

	int dcnt = 0;// ����idx +1 ���ٶ� ���.
	//int hcnt = 0;// 1������ ������ �� �߰�(+1)�ɶ� ��� -> ����+1 ���ٶ� 0���� �ʱ�ȭ���ֱ�.
	

	scanf_s("%d", &n);

	//1. ������ �� �Է¹ޱ� (���� ���� ������ �Է�)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &arr[i][j]);
			//printf("%d ", arr[i][j]);
		}
		//printf("\n");
	}

	//2. 2���� �迭�� ����� �� �߿���,
	//1�� ������ �ʰ� �̾����� ��� �ϳ��� ������ ������ش�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checked[i][j] == false) { //Ž�� ����
				checked[i][j] = true;
				
				if (arr[i][j] == 0) //0�̸� checked�ϰ� �Ѿ
					continue;
				else if (arr[i][j] == 1) {
					//hcnt = 0;
					dcnt += 1;
					printf("(%d,%d)����! \n", i, j);
					find_danji_ofhome(i, j, dcnt, 1);
					//danji[dcnt] = homes;
					scnt = 0;
					printf("danji: %d = %d\n", dcnt, danji[dcnt]);
				}
			}
			else  continue;
		}
	}
	// 1�� ������ 1�� ã�� �����¿츦 ������ . ��� ��찡 0���� ���� �Ǹ� 
	//��ġ�� ���� �κп��� ���� ���� [][]���� �ٽ� ������ ..? (Ȯ������ ���� ��)

	// �̹� ���� ������ passed[][]�迭�� true�������ϱ� .
	//�����¿츦 Ȯ���ҋ� passed�� true�� ���̸�, �����ϰ� , ĭ���� ũ�� �����ϰ�,
	// 0�̸� passed true�ϰ� �װ����� �����¿� Ȯ���� �ʿ���� 
	//- ���ݱ����� ���ڸ� �����迭�� ����

	//������� ����ϱ� ���� sort��Ŵ
	int size= sizeof(danji) / sizeof(danji[0]);
	sort(danji, danji+size);

	//5. ����� ���� �迭�� sort���Ѽ� ������ ���ϴ� ���� ���� �����
	for (int i = 0; i < size; i++) {
		if (danji[i] != 0) {
			printf("%d\n", danji[i]);
		}
	}

	return 0;
}
*/

//�ٽ��ϱ� ..
/*
#include <stdio.h>
#include <set>
using namespace std;
int N;
int map[27][27];
int home[27][27];
int danji = 0;
int cnt = 0;
//set <pair<int, int>> s;
set<int>s;
int main() {
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]); // 0 �Ǵ� 1 �Է¹ޱ�
		}
	}
	
	for (int i = i; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) {
				home[i][j] = 0;
				continue;
			}
			else if (map[i][j] == 1) {
				if (i - 1 < 1 && j - 1 < 1) {
					//���� �� �Ѵ� �˻� �ʿ����
					danji++; //cnt = 1;
					home[i][j] = danji;
					//s.insert(danji, 1);
				}
				else if (i - 1 < 1) {//�� �˻� �ʿ����
					//���� 0�� ���
					if (map[i][j - 1] == 0)
					{
						danji++; //cnt = 1;
						home[i][j] = danji;
						//s.insert(danji, 1); 
					}
					//���� 1�� ���
					else {
						home[i][j] = danji; //���� ���� ���� ������� 
						//�������� ���� ã�ƿ��¹�� ....?
						if (s._Getpfirst == danji) {
							cnt = s.second
						}
						//s.insert(danji, cnt + 1);
					}
				}
				else if (j - 1 < 1) {//�� �˻� �ʿ����
					//���� 0�� ���
					if (map[i - 1][j] == 0) {
						danji++; //cnt=1;
						home[i][j] = danji;
						s.insert(danji, 1);
					}
					//���� 1�� ���
					else {

					}
				}
				else { //���� �� �Ѵ� �˻� �ʿ� 
					//������ 0�ΰ��

					//������ 1�ΰ�� (���� ���� �������� �ٸ� �������� Ȯ���ؾ���)
					//home �� ���� �̿��ؼ� ���ϱ� ..
					//���� 0�̰� ���� 1�ΰ��

					//���� 1�̰� ���� 0�ΰ��

				}
			}

		}
	}
	return 0;
}
*/