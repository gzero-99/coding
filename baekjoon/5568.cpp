
//������ ���� #5568 ī����� c++ ��
#include <iostream>
#include <set>
#include <string>
using namespace std;
bool check[10];
int card[11]; //n�� ī�尪 ���� 
int num[5]; //k�� ī�尪 ���� 
set <string> s; // �ߺ� �����ϰ� ������ �������� .

				//2,3,4��k�� ������ 
				//k�� ���� ������ set�� �������ֱ� .
void make(int idx, int n, int k) {
	if (idx == k) {
		int yet = 0;
		string temp = "";
		for (int i = 0; i < k; i++) {
			string str;
			str = to_string(num[i]);
			temp += str;
		}
		s.insert(temp);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == true) continue; //�̹� ����� ����	
			check[i] = true;
			num[idx] = card[i]; //num �迭�� ���ڸ� �߰�
			make(idx + 1, n, k); //num �����ε����� ���ڸ� �߰��ϱ����� ����
			check[i] = false; // �ٽ� üũ����
		}
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	make(0, n, k);
	cout << s.size();
	return 0;
}


/*
//����! ����ϴ� ������ �ִ� ���� 
#include <iostream>
#include <set>
#include <string>
using namespace std;
bool check[10];
int card[11]; //n�� ī�尪 ���� 
int num[5]; //k�� ī�尪 ���� 
set <string> s; // �ߺ� �����ϰ� ������ �������� .

			 //2,3,4��k�� ������ 
			 //k�� ���� ������ set�� �������ֱ� .
void make(int idx, int n, int k) {

	if (idx == k) {
		int yet = 0;
		string temp="";
		for (int i = 0; i < k; i++) {
			string str;
			str = to_string(num[i]);
			temp += str;
			cout << temp<<" ";
		}
		cout << endl;
		s.insert(temp);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == true) continue; //�̹� ����� ����	
			check[i] = true;
			num[idx] = card[i]; //num �迭�� ���ڸ� �߰�
			make(idx + 1, n, k); //num �����ε����� ���ڸ� �߰��ϱ����� ����
			check[i] = false; // �ٽ� üũ����
		}
	}
}
int main() {
	int n, k;

	cin >> n >> k;
	//n�� ī�� �� ���� 
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	//n���� ī�忡�� k�� �̱� - �ߺ����� ��µǵ����ϱ�.
	make(0, n, k);
	set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	cout << s.size(); //������ִ� ������ ���� ���.

	return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
bool check[10];
int card[11]; //n�� ī�尪 ���� 
int num[5]; //k�� ī�尪 ���� 
set <int> s; // �ߺ� �����ϰ� ������ �������� .

//2,3,4��k�� ������ 
//k�� ���� ������ set�� �������ֱ� .
 void make(int idx, int n, int k) {

	 if (idx == k) {
		 int yet = 0;
		 for (int i = 0; i < k; i++) {
			 yet = yet + num[i]*pow(10, k-i-1);
		 }
		 s.insert(yet);
		 return;
	 }
	 else {
		 for (int i = 0; i < n; i++) {
			 if (check[i] == true) continue; //�̹� ����� ����	
			 check[i] = true;
			 num[idx] = card[i]; //num �迭�� ���ڸ� �߰�
			 make(idx + 1, n, k); //num �����ε����� ���ڸ� �߰��ϱ����� ����
			 check[i] = false; // �ٽ� üũ����
		 }
	 }
}
int main() {
	int n, k;

	cin >> n >> k;
	//n�� ī�� �� ���� 
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	//n���� ī�忡�� k�� �̱� - �ߺ����� ��µǵ����ϱ�.
	make(0, n, k);
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	cout << s.size(); //������ִ� ������ ���� ���.
	
	return 0;
}
*/

/*
#include <stdio.h>
#include <set>
using namespace std;
set <int> s;
int n;
int k; // 2<=k<=4
int card[11];//4<=n<=10
int pick[5]; //kũ�� �迭 - ���õ� ī����� ������ȴ�
//k-1���� �����ص־��� .. 
//midx �� k-1 �� .
void card_sel(int sidx, int midx, int eidx ,int pidx) { //ī�� k�� ���ÿ� ��� 
	//���� �� , �߰� ��, �� ��
	//���� �ܰ� 
	for (int j = 0; j < k; j++) { //k�� �迭 ä��� ..............

	}
	for (int i = sidx; i < midx; i++) {

	}
	
	card_sel(sidx+1, midx, eidx,pidx);

}
void make_num(int cnt) { //k�� ī��� ���� ����⿡ ��� 

}
int main() {

	scanf_s("%d", &n);
	scanf_s("%d", &k);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &card[i]);
	}

	//1. k�� ī�带 �����Ѵ�

	//2. ������ k���� ī����� ������ �����Ѵ�.
	//kũ�� �迭�� ������ ������ �����Ѵ�.

	//3. ������ ������ set�� �����Ѵ�.

	//4.set�� �ߺ� ������ ���� �����Ƿ�, ����̰� ���� �� �ִ� ������ ���� ��°��� 
	printf("%d", s.size());
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
vector <string> v;
set <string> s;
int n;
int k;
//int card[11];
string card[11];

void makeNum( int idx1 , int idx2, int cnt) {

	for (int i = 0; i < n; i++) {
		v.push_back(card[i]);
		makeNum(idx1 + 1, idx2, cnt);
	}
}
int main() {
	int num[5]; //k�����ŭ.
	cin >> n;//scanf_s("%d", &n); //4<= n <=10
	cin >> k;//scanf_s("%d", &k);  //2<=k<=4
	for (int i = 0; i < n; i++) {
		//scanf("%d", &card[i]);//1<=card�� ���� ����<=99
		cin >> card[i];
	}

	return 0;
} 
*/

/*
void swap(int idx1, int idx2) {
	int tmp = card[idx1];
	card[idx1] = card[idx2];
	card[idx2] = tmp;
}*/
/*
void makeNum(int idx,int cnt , int num[]) {
	if (cnt == k) {
		for (int i = 0; i < k; i++)
			s.insert(num[i]);
		return;
	}
	for (int i = 0; i < cnt; i++) {
		//
	}
}*/

	
	
	/*
	//�ߺ��� ������� �ʴ� ����
	[0	1	2	3]
	1, 2 , 12, 1
	(1) 1, 2 ���� [0,1]-> 1+2 ,2+1 
	(2) 1, 12 ���� [0,2]-> 1+12 , 1+21
	(3) 1, 1 ���� [0,3] -> 1+1 ,1+1 
	(4) 2, 12 ���� [1,2]-> 2+12, 12+2
	(5) 2, 1 ���� [1,3]-> 2+1 , 1+2
	(6) 12, 1 ����  [2,3] ->12+1, 1+12
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){ 
		....
		}
	}
	������ �׳� idx�����ָ� �ǰ� ,,?
	������ 6�� �ϰ� , ���� ���� ����� �Ŵ� ...
	������ ���ڵ� ����(k) ��ŭ�� �� �����ؼ� set�� �������ָ� �� 
	�����ϴ°� -> �ߺ��� ������� �ʴ� ������ ..?

	���� ���� ���� �����ϰ�� , �� 7�� 
	*/
