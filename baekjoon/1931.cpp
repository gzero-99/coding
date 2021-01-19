//������ [����] #1931 ȸ�ǽǹ��� c++ ��
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int n;
	int x[100001];

	//�Է�
	cin >> n;
	vector <pair <int, int>> v(n);
	for (int i =0; i <n; i++) {
		cin >> v[i].second; //���� �ð� ����
		cin >> v[i].first; //������ �ð� ����
	}

	//���� ���� ������ ���ǵ� ������ ���� - vector���.
	sort(v.begin() , v.end());

	//�׸���
	int cnt = 0;
	x[0] = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= x[cnt] ) { //�����ϰ� ���� ���� ���� �ð�.
			cnt += 1;
			x[cnt] = v[i].first; //����ð� ���� 
			//cout << "����ð� : " << x[cnt];
		}
	}

	cout << cnt+1;
	return 0;
}


/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

����� 4���� ��
*/