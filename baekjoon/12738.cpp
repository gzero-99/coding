//#12738 ����� �����ϴ� �κм���3 (2�� ���� - �߰��� �� ����)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int main() {
	int N;
	cin >> N;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (v.empty() || v.back() < num)
			v.push_back(num);
		else {
			auto iter = lower_bound(v.begin(), v.end(), num);
			*iter = num;
			//������ ���������� ���� ������, lower_bound�� ã�´�
			//������ ���Ե� �� num���� ũ�ų� ���� ù ������ iterator�� ��ȯ�Ѵ�.
		}
	}
	cout << v.size();
	return 0;
}