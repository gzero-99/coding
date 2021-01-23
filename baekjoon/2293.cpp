//������ [���� ] #2293 ����1 c++ ��
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001]; // ���������� �ϸ� 0���� �⺻ �ʱ�ȭ �Ǿ�����.

int main() {
	int n, k;
	cin >> n >> k;
	int coin[101];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + n ); // ���� ũ������� ����

	if (k == 1) {
		cout << 1;
	}
	else {
		dp[0] = 1; // �⺻ 1
 
		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= k; j++) {
				dp[j] += dp[j - coin[i]]; // �ٸ� �׼��� �������� �ٲܼ������Ƿ� ����
			}
		}
		cout << dp[k];
	}
	return 0;
}

/