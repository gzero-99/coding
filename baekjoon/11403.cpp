//[����] #11403 ���ã��

#include <iostream>
using namespace std;
int N;
bool G[100][100];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> G[i][j]; // 0�̸� i->j ���� ���� , 1�̸� i->j ���� ����.

	for (int k = 0; k < N; k++) { //���İ��� ���
		for (int i = 0; i < N; i++) { //��� ���
			for (int j = 0; j < N; j++) { //���� ���
				if (G[i][k] == 1 && G[k][j] == 1)
					G[i][j] = 1;
			}
		}
	}
	//����ϱ�  : ����i->j ���� ��ΰ� �ִٸ�, i��° ����j��° ĭ�� 1ǥ��.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << G[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}