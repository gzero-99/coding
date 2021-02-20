//[����] 11404 �÷��̵� 
#include <iostream>
#define INF 987654321
#define MIN(a,b) a<b?a:b
using namespace std;
int arr[100][100];	// ����-���÷� ���µ� ��� ��� ���� �迭

int main() {
	int N, M;
	int A, B, C;
	// �������۵��� , �������� , �ѹ� Ÿ�� �� �ʿ���(�ڿ���<=10000)

	cin >> N;	// 2<=n<=100�� ���� 
	cin >> M;	//1<=m<=100,000�� ����

				//���� �Է¹ޱ�
	int m = 0;	//m�� �ٿ� ������ ���� 
	while (m < M) {
		m++;
		cin >> A >> B >> C;
		if (arr[A - 1][B - 1] != 0) {//���� ��θ�,  �� ��� �� �� ����
			arr[A - 1][B - 1] = MIN(arr[A - 1][B - 1], C);
		}
		else arr[A - 1][B - 1] = C;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) //����������
				arr[i][j] = INF; //����ū���ֱ�
		}
	}

	//������ �� (A,B) A->B�� �ʿ��� �ּ� ��뱸�ϱ�
	//�÷��̵� - �˰���
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}

	}

	//i->j ���÷� �� �� ���� ��� 0 ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i == j))	cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
/*
//��¿�������
#include <iostream>
#define INF 987654321
#define MIN(a,b) a<b?a:b
using namespace std;

int arr[100][100];	// ����-���÷� ���µ� ��� ��� ���� �迭

int main() {
	int N, M;
	int A, B, C;	
	// �������۵��� , �������� , �ѹ� Ÿ�� �� �ʿ���(�ڿ���<=10000)
	
	cin >> N;	// 2<=n<=100�� ���� 
	cin >> M;	//1<=m<=100,000�� ����

	//���� �Է¹ޱ�
	int m = 0;	//m�� �ٿ� ������ ���� 
	while (m < M) {
		m++;
		cin >> A >> B >> C;
		if (arr[A - 1][B - 1] != 0){//���� ��θ�,  �� ��� �� �� ����
			arr[A - 1][B - 1] = MIN(arr[A - 1][B - 1], C);
		}
		else arr[A - 1][B - 1] = C;
		cout << "m : "<<m<< "  C = "<<arr[A - 1][B - 1]<<endl;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
			if (arr[i][j] == 0) //����������
				arr[i][j] = INF; //����ū���ֱ�

		}
		cout << endl;
	}

	//������ �� (A,B) A->B�� �ʿ��� �ּ� ��뱸�ϱ�
	//�÷��̵� - �˰���
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
		
	}

	//i->j ���÷� �� �� ���� ��� 0 ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i==j))	cout << 0 << " ";
			else cout << arr[i][j] <<" ";
		}
		cout << "\n";
	}
			
	return 0;
}

*/