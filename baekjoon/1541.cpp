//���� 1541  �Ҿ���� ��ȣ 
#include <iostream>
#include <string>
using namespace std;

string str = "";

int main() {
	cin >> str;
	int rst = 0;
	bool minus = false; //�������� Ȯ�ο�
	string num = ""; //�ǿ����� ����

	for (int i = 0; i <= str.size(); i++) {
		//������ ������ 
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus == true)
				rst -= stoi(num); //���� ����
			else
				rst += stoi(num); //���� ���ϱ�

			num = "";//�ʱ�ȭ���ְ�,
			//��ȣ�� �����϶� ����~���ָ� ��
			if (str[i] == '-')
				minus = true;
			continue;
		}
		//�ǿ����ڶ��
		num += str[i];
	}
	cout << rst;
	return 0;
}