//[bj] 2346 풍선 터트리기 
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<pair<int, int>> v;
	int N, tmp;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		v.push_back({ i, tmp });
	}

	int idx = 0;
	while (1) {
		printf("%d", v[idx].first);
		int n = v[idx].second;
		v.erase(v.begin() + idx); // 터트린 풍선은 지운다.

		if (v.empty()) break;


		if (n > 0) {
			idx += (n-1);
			idx = idx % v.size();
		}
		else {
			idx += n;
			if (idx < 0) {
				idx *= -1; //양수로 
				idx = idx % v.size();
				idx = v.size() - idx;
				idx = idx % v.size();
			}
		}
		printf(" ");
	}
	return 0;
}


/*
if (n > 0) { //양수만큼 움직여야 한다면
n--;
if (idx + n > v.size() - 1)
idx = idx + n - v.size();
else
idx = idx + n;
}
else {
n++;
if (idx + n < 0)
idx = v.size() + idx + n;
else
idx = idx + n;
}
*/

/*
if (n > 0) {
n--;
idx += n;
idx = idx % (v.size()+1);
}
else {
n *= -1;
idx -= n;
//if (idx < 0) idx += v.size() ;
if (idx < 0) idx = -(idx % v.size());

}
*/