// #1966 baekjoon printer queue 
#include <iostream>
#include <queue>
#include <functional>
#include <stdbool.h>
using namespace std;

int main() {
	int TC;
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		//input
		int N, M;
		queue <pair<int, int>> q; //first�� index, second�� importance
		priority_queue<int > pq; //�켱���� ť 
		int cnt=0;

		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			q.push(make_pair(j, tmp)); 
			pq.push(tmp);
		}

		//SangGun's printer sw algorithm
		while (!q.empty()) {
			int idx = q.front().first;
			int imp = q.front().second;
			q.pop(); //�� �־��ְ� pop��Ű�� - �̵��� �ڿ� �ٿ��ٿ��� 

			if (pq.top() == imp) { 
				//���� �߿䵵�� ���� ū ���� pq�� top�� ����. 
				//�� �߿䵵�� imp�� ���� ?
				pq.pop();
				cnt++;
				//������ �� back�� �ٿ��� �ʿ���� �Ѿ��, idx�� ������ Ȯ��
				if (idx == M) {
					//output
					cout << cnt << endl;
					break;
				}
				
			}
			else {//�ٸ��� back�� �ٿ��ش�.
				q.push(make_pair(idx, imp));
			}
		}
	}
	return 0;
}