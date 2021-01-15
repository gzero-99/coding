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
		queue <pair<int, int>> q; //first는 index, second는 importance
		priority_queue<int > pq; //우선순위 큐 
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
			q.pop(); //값 넣어주고 pop시키기 - 이따가 뒤에 붙여줄예정 

			if (pq.top() == imp) { 
				//현재 중요도가 가장 큰 놈이 pq의 top에 있음. 
				//그 중요도가 imp와 같음 ?
				pq.pop();
				cnt++;
				//같으면 걔 back에 붙여줄 필요없이 넘어가고, idx가 같은지 확인
				if (idx == M) {
					//output
					cout << cnt << endl;
					break;
				}
				
			}
			else {//다르면 back에 붙여준다.
				q.push(make_pair(idx, imp));
			}
		}
	}
	return 0;
}