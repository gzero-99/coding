//[����] #11780 �÷��̵�2 c++

#include <iostream>
#include <string>
#define INF 987654321
#define MIN(a,b) a<b?a:b
using namespace std;
int arr[100][100];	// ����-���÷� ���µ� ��� ��� ���� �迭
int path[100][100]; // �ִܰ�� �� ������ ��� ����
int between = 0;
string result;
void PrintPath( int start, int end) {
	if (path[start][end] != -1) {
		PrintPath(start, path[start][end ]);
		string s = to_string(path[start][end]+1);
		result.append(s);
		result.append(" ");
		between++;
		//cout << "\nbetween: "<<between << " ";
		PrintPath (path[start][end ], end);
	}
}  

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
			path[i][j] = -1;
		}
	}

	//������ �� (A,B) A->B�� �ʿ��� �ּ� ��뱸�ϱ�
	//�÷��̵� - �˰���
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
				if (arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
					//�߰� ��� �����ϱ� �߰�
					path[i][j] = k;
				}
			}
		}

	}

	//i->j �迭��� && ���÷� �� �� ���� ��� 0 ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i == j))	cout << 0 << " ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}


	//�÷��̵� 2 �߰� �κ� : i->j �ּҺ�� ��ο� �ִ� ���� ���� && ���� ��� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == INF || (i == j))	cout << 0 << "\n";
			else {
				PrintPath(i, j);
				if (result.compare("")==0)//���ڿ��̶��..
					cout << 2 + between << " " << i + 1 << " " << j + 1 << "\n";
				else
					cout << 2 + between << " " << i + 1 << " " + result << j + 1 << "\n";
				between = 0;
				result = "";
			}
		}
	}
	return 0;
}

/*

	//path ��¿���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			 cout << path[i][j] << " ";
		}
		cout << "\n";
	}
*/