//sw #3752 ������ ���� ����

#include <iostream>
#include <cstring>
using namespace std;
int N;
int arr[100];
int score[10000]; //0 ~ 10000���� ���� ����.
int rst;

int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		memset(score, 0, sizeof(score)); //�ʱ�ȭ
		rst = 0;
		cin >> N;

		score[0] = true; //0���� �� �������
		int max = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i]; //���� �Է�
			max += arr[i]; //���� �� �ִ� �ִ� ����
			for (int j = max; j >= 0; j--) {
				if (score[j]) //j�� �ش��ϴ� ������ �ִٸ� ,
					score[j + arr[i]] = true; //j+�����Է��� ������ ������ �ֵ���
			}
			score[arr[i]] = true;//���� �Է��� ������ ������ ���
		}
		for (int i = 0; i <= max; i++)//0~�ִ���������
			if (score[i])rst++;//������ �����Ѵٸ� ������ ���� ����� ���� ������.

		
		//�л����� ���� �� �ִ� ������ ����� �� .
		cout << "#" << tc << " " << rst << endl;
	}
	return 0;
}


/*
#include <iostream>
using namespace std;
int N;
int score[100];
int result[100];
bool visited[100];
int rst,cnt;

void count_score(int idx) {
	if (idx >= N) {
		rst++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			result[idx] = score[i];
			visited[i] = true;
			count_score(idx + 1);
			visited[i] = false;
		}
	}
}


int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		rst = 0, cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> score[i];

		count_score(0);
		//�л����� ���� �� �ִ� ������ ����� �� .
		cout << "#" << tc << " " << rst;
	}
	return 0;
}
*/