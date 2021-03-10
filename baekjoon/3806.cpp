//Baekjoon g0 #3806 S to T ��

#include <iostream>
#include <string>
#define MAX 101
using namespace std;
int main() {
	int TC;
	string S, T;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> S >> T;
		int  Sqcnt = 0,t1 = 0;//? ���ڿ� ���� ,  �ٸ� �κ� �� t���ڿ� 1�� ����
		int s0 = 0, s1 = 0; // s�� t���ڿ� ��������, �ٸ� �κ� �� s���ڿ��� ���ڰ���.
		int rst = 0;
		int Tnum[MAX];	//t���ڿ� ����. s���ڿ��� �񱳽� ���.

		int k = 0;
		for (string::iterator iter = T.begin(); iter != T.end(); ++iter) {
			char c = *iter;
			Tnum[k] = c - '0';
			k++;
		}
		k = 0;
		for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
			char c = *iter;
			if (Tnum[k] != (c-'0')) { //s�� t ���ڿ� �ٸ� �κ�
				if (Tnum[k] == 1)
					t1++; //1���ʿ��ѵ�, s�� ?�� 0�� �ִ� ���.

				if (*iter == '0')
					s0++;	//s�� 0�϶�, 0->1�̳� ��ȯ���� 
				else if (*iter == '1')
					s1++;	//s�� 1�϶�, ��ȯ������� 
				else
					Sqcnt++; //? �� �� (������ 0�̳� 1�� )
			}
			k++;
		}
		//** s���ڿ����� ������ �۾� 0->1 , ? ->1 , ? ->0 , 0<->1(��ȯ)

		if (s0 + s1 + Sqcnt != 0) { //s�� t�� �ٸ� �κ��� ������
			if (s1 > t1) //s�� t�� �ٸ� �κ� �߿�����, s�� 1�� ���� > t�� 1�� ������ -1 ��� 1->0�Ұ����װ�.
				rst = -1;
			else {
				if (s0 == s1)	
					rst = s1 + Sqcnt;
				else if (s0 < s1) // s1�� �� ũ�� s1�����ֱ�
					rst = s1 + Sqcnt;
				else			//s0�� �� ũ�� s0�����ֱ�.
					rst = s0 + Sqcnt;
			} //0<->1 ��ȯ (s0 Ȥ�� s1) / �׸��� �����͵��� ?�� �ٲ��ִ� �� (Sqcnt) = �ּ� ������ �� 
			
		}
		//output
		cout << "Case " << i << ": " << rst << endl;
	}
	return 0;
}


/*
#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int main()
{
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		int rst = 0;
		int S0cnt = 0, S1cnt = 0, Sqcnt = 0, T0cnt = 0, T1cnt = 0;
		string S, T;
		cin >> S;
		cin >> T;
		int Tnum[MAX];
		int k = 0;
		for (string::iterator iter = T.begin(); iter != T.end(); ++iter) {
			if (*iter == '0')
				T0cnt++;
			else if (*iter == '1')
				T1cnt++;
			char c = *iter;
			Tnum[k] = c - '0';
			k++;
		}
		k = 0;
		int s0 = 0, s1 = 0;
		for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
			if (*iter == '0') {
				S0cnt++;
				if (Tnum[k] != 0)  //��ġ�� �ٸ��� �߰����� ..//1�� �ʿ��ѵ�, 0�� ������
					s0++;
			}
			else if (*iter == '1') {
				S1cnt++;
				if (Tnum[k] != 1) //0�� �ʿ��ѵ� 1�� ������,
					s1++;
			}
			else  //?�� ���
				Sqcnt++;
			k++;
		}

		if (Sqcnt == 0 && S0cnt < T0cnt ) //?�� ������,s: 1->0�� �Ұ��� (T0cnt�� S0cnt���� ������ �ƿ�)
			rst = -1;
		else if (Sqcnt==0 && S1cnt <=T1cnt) {//?�� ���� �� ,s: 0->1�� ���� .. 
			rst += T1cnt-S1cnt; //t�� �ٸ� 0�� ������ŭ  �ٲ��� .
			int tmp = rst;
			//�׸��� ��ġ �ٲٴ°� ..?
			rst += s0 - tmp;
		}
		else {//?�� �ִ� ����.
			//?�κ��� 0�Ǵ� 1�� �ٲ��ټ�����. (s�� t�� �°� �˾Ƽ� �ٲٸ� ��) //rst += Sqcnt;
			//�ٸ�! 0->1�ؼ� 1�� ������ �ø��������� . 0�� ������ �ø��������Ƿ�! 0�� ������ ���ľ��ؼ� ������ ��ŭ ?���� ���������� 
			int zero, one;
			if (S0cnt < T0cnt) { //�ʿ��� 0�� ������ �����ϴ� 0�� �������� ������ . ?�� 0�� ���������� ..
				if (Sqcnt < T0cnt) { //�ʿ���0�� ������?���� ������ 
					rst = -1; //�ȵ�
					}
				else {
					zero = Sqcnt - S0cnt;//? ->0
					rst += zero;
					if (S1cnt < T1cnt) {//�ʿ��� 1�� ������ �� ������ ..
						if (Sqcnt -zero> T1cnt) {
							one = T1cnt;
							rst += one;
						}
						else { //?���� 1�� �� ���� �ʿ��ϸ� ..
							//0->1������� !
							//if (s0 >= ) {
								//���� ..
							//}
						}
					}
				}
				//?�� �� ������ŭ 0���� ������ش�
				//rst += T0cnt - S0cnt;
				//int tmp = rst;
				//���� ?�� 1�� ������ش�
				//rst += Sqcnt - tmp;

			}
			else if (S0cnt > T0cnt) {//�ʿ��� 0�� ������ �����ϴ� 0�� �������� ������ .. 0->1�������
				if (Sqcnt > s0) {
					rst = -1; //? �������� �ʿ��� 0�� ������ ������. �Ұ���
				}
				else {
					one = Sqcnt - s0;//1�� �ٲܼ��ִ� ���� ?�� ����
					rst += s0;
					if (S1cnt < T1cnt) {
						rst += one; //�ϴ� ���� ? ������ŭ �ٲ��ְ�.
						zero = 0;
						//��ġ �ٸ��� �����ִ°Ŵ� ��������!
					}

				}

			}


			if (rst == -1) {

			}
			else {

			}

			//����
			if (S0cnt < T0cnt)
				zero = T0cnt - S0cnt;
			else if (S0cnt > T0cnt) {
				zero = S0cnt - T0cnt;
			}
			else if (S0cnt == T0cnt)
				zero = 0;

			if (S1cnt < T1cnt)
				one = T1cnt - S1cnt;
			else if (S1cnt > T1cnt)
				one = S1cnt - T1cnt;
			else
				one = 0;

			if (zero + one != Sqcnt)
				rst = -1; //������ �� ������ �ٸ��� �ȵ�
			else
				rst += Sqcnt; //?�� 0�̳� 1�� ���� ���� �����ְ�.

							  //?�� �ִ� ���� 0�� 1�� ��ȯ���ذ� ��������
							  //���� ?�� �ִ� ���� �ԷµȰͰ� �ٸ� ��ġ�� �͵��� ã�� ���������.
			k = 0;
			for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
				if (*iter == '?') { //?�� ���
									//0�� �ʿ��ϰ�, 0�� �������
									//cout << "Tnum["<<k<<"] : "<<Tnum[k]<<endl;
					if (Tnum[k] == 0 && zero > 0) {
						zero--;
					}
					//0�� �ʿ�������,0 �� ���� ���,1�� ����
					else if (Tnum[k] == 0 && zero == 0) {
						one--;
						s1++;
					}
					//1�� �ʿ��ϰ�, 1�� �������
					else if (Tnum[k] == 1 && one > 0) {
						one--;
					}
					//1�� �ʿ��ϰ�, 1�� ���� ��� , 0�� ����
					else if (Tnum[k] == 1 && one == 0) {
						zero--;
						s0++;
					}
				}
				k++;
			}
			rst += s0; // ���� s0�� s1�� ������ ������ ���ƾ��� ..



		}//?�� �ִ� ���� ��.

		 //output
		//cout << "Case " << i << ": " << rst << endl;
		
	}
	return 0;
}
*/

//Baekjoon g0 #3806 S to T �� - ���� ��ü�� �߸��� 

/*
#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int main()
{
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		int rst = 0;
		int S0cnt = 0, S1cnt = 0, Sqcnt = 0, T0cnt = 0, T1cnt = 0;
		string S, T;
		cin >> S;
		cin >> T;
		int Tnum[MAX];

		int k = 0;
		for (string::iterator iter = T.begin(); iter != T.end(); ++iter) {
			if (*iter == '0') 
				T0cnt++;
			else if (*iter == '1') 
				T1cnt++;
			char c = *iter;
			Tnum[k] = c - '0';
			k++;
		}
		k = 0;
		int s0 = 0, s1 = 0;
		for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
			if (*iter == '0') {
				S0cnt++;
				if (Tnum[k] != 0)  //��ġ�� �ٸ��� �߰����� ..//1�� �ʿ��ѵ�, 0�� ������
					s0++;
			}
			else if (*iter == '1') {
				S1cnt++;
				if (Tnum[k] != 1) //0�� �ʿ��ѵ� 1�� ������,
					s1++;
			}
			else  //?�� ���
				Sqcnt++;
			k++;
		}

		if (Sqcnt == 0 && (S0cnt != T0cnt || S1cnt != T1cnt))
			rst = -1;
		else if (Sqcnt == 0 && (S0cnt == T0cnt && S1cnt == T1cnt)) {
			//?�� ����, 0��1�� ������ �������
			//�ٸ� ��ġ�� �ִ����� Ȯ���ϸ� ��
			if (s0 == s1) 
				rst += s0; //��ġ ��ȯ���� �ֵ�
		}
		else {//?�� �ִ� ����.
			int zero, one;
			if (S0cnt < T0cnt) 
				 zero = T0cnt - S0cnt;
			else if (S0cnt > T0cnt) {
				zero = S0cnt - T0cnt;
			}
			else if (S0cnt == T0cnt) 
				zero = 0;

			if (S1cnt < T1cnt)
				one = T1cnt - S1cnt;
			else if (S1cnt > T1cnt)
				one = S1cnt - T1cnt;
			else
				one = 0;

			if (zero + one != Sqcnt)
				rst = -1; //������ �� ������ �ٸ��� �ȵ�
			else
				rst += Sqcnt; //?�� 0�̳� 1�� ���� ���� �����ְ�.

			//?�� �ִ� ���� 0�� 1�� ��ȯ���ذ� ��������
			//���� ?�� �ִ� ���� �ԷµȰͰ� �ٸ� ��ġ�� �͵��� ã�� ���������.
			k = 0;
			for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
				if (*iter =='?'){ //?�� ���
					//0�� �ʿ��ϰ�, 0�� �������
					//cout << "Tnum["<<k<<"] : "<<Tnum[k]<<endl;
					if (Tnum[k] == 0 && zero > 0) {
						zero--;
					}
					//0�� �ʿ�������,0 �� ���� ���,1�� ����
					else if (Tnum[k] == 0 && zero == 0) {
						one--;
						s1++;
					}
					//1�� �ʿ��ϰ�, 1�� �������
					else if (Tnum[k] == 1 && one > 0) {
						one--;
					}
					//1�� �ʿ��ϰ�, 1�� ���� ��� , 0�� ����
					else if (Tnum[k] == 1 && one == 0) {
						zero--;
						s0++;
					}
				}
				k++;
			}
			rst += s0; // ���� s0�� s1�� ������ ������ ���ƾ��� ..

		}//?�� �ִ� ���� ��.


		//output
		cout << "Case " << i << ": " << rst;
	}
	return 0;
}
*/