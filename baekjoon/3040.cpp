//[����] �鼳���ֿ� �ϰ� ������ 
#include <iostream>
using namespace std;
int num[9];
bool ans[9];//true�� ���߿� ���~
int sum, num1, num2;

void find_dwarf() {
	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			//��ü�տ��� 2�� ������ ��, 100�� �Ǵ� �� ã��
			if (sum - num[i] - num[j] == 100) {
				if (i != j)//�׸��� ���� �ٸ� �ָ�?
				{
					num1 = num[i];
					num2 = num[j];//�������ֱ�
					return;
				}
			}
		}

	}
}

int main() {
	for (int i= 0; i < 9; i++) {
		cin >> num[i];
		sum += num[i]; //��ü�� ����
	}
	find_dwarf();


	//������ ���� ���� �� �ٸ��ٰ� ������,
	for (int i = 0; i < 9; i++) {
		//�ΰ� ���ڰ� �ƴ϶�� ������� ..
		if (num[i] != num1 && num[i] != num2)
			cout << num[i] << endl;
	}
	return 0;
}
/*

�� ���ڿ� 100���� ���� ���� ���� ����
7������ ������ ������ ���� 100�ǵ��� �����
��ȩ �����̿� ���� ���� �־�����,
������ ã����

=> 9���� �� �� ���� 100�Ǵ� �ϰ� ���� �� ã��

�Է� 1<=N<=99 �ڿ��� 9�� �ٿ�
�� �ٸ� ��
���� �����ϵ��� �־���

*/
