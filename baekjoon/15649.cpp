

//15649 n�� m c++
#include <iostream>
using namespace std;

int arr[10];
bool check[10];
void make(int idx, int n, int m) {

	//�ε����� m��°�� �Ǹ� ����ϱ�.
	if (idx == m) {
		for (int i = 0; i < m; i++) {//m���� ����
			cout << arr[i];
			if (i!= m - 1)cout << ' '; //���ڿͼ��� ���̿� �������
		}
		cout << '\n';
		return; //Ż��
	}
	//���ڴ� 1~n�� ��� 
	for (int i = 1; i <= n; i++) {
		if (check[i] == true) continue; //�̹� ����� ����

		//�� ���ڸ� üũ�ϰ�
		check[i] = true; 
		arr[idx] = i; //arr �迭�� ���ڸ� �߰�
		make(idx + 1, n, m); //arr �����ε����� ���ڸ� �߰��ϱ����� ����
		check[i] = false; // �ٽ� üũ����
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	make(0, n, m);
	return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//���� ���ڵ��� �迭�� �����ϰ� , �˰��� ������.
//���� �˰��� 
void Permutation(vector<int>& Array, int Start, int End)
{
	if (Start == End)
	{
		for (const auto it : Array)
		{
			cout << it << " ";
		}
		cout << endl;


	}
	else
	{
		for (int i = Start; i <= End; ++i)
		{
			swap(Array[Start], Array[i]);
			Permutation(Array, Start + 1, End);
			swap(Array[Start], Array[i]);
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	//int num[9];
	//for (int i = 1; i <= n; i++) {
	//	num[i] = i;
	//}//1~n���� ����
	int num[] = {1,2,3,4,5,6,7,8}; 
	vector <int> arr;
	set <int> numArr;
	//m�� �̱�
	for (int i = 0; i < n; i++) {
		arr.push_back(num[i]);
	}
	while (m > 0) {

		m--;
	}
	Permutation(arr, 0, n-1);
	return 0;
}
*/