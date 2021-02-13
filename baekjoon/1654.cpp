//���� #1654 �����ڸ���
#include <iostream>
#include <algorithm>
using namespace std;
int lgt[10000];
int N, K;

int binary_search() {
	long long left = 1; //2�� 31�� -1�̹Ƿ� long long���
	long long right = lgt[K - 1];
	while (left <= right) {
		long long mid = (left + right) / 2;
		int tmp = 0;
		for (int i = 0; i < K; i++)
			tmp += (lgt[i] / mid);

		if (tmp < N)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right;
}
int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> lgt[i];
	sort(lgt, lgt + K);
	cout << binary_search() << endl;
	return 0;
}
