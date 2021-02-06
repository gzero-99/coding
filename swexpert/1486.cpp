//#1486 [sw] �������� ���� ���� 
#include <iostream>
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;
int H[20];

int main() {
	int TC, N, B;
	cin >> TC, N, B;

	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> B;
		for (int i = 0; i < N; i++)
			cin >> H[i];

		//N�� ��Ʈ 00001->00010->00011->...�˻��ϱ�
		int sum, mi = 200000; //20���� �ִ�
		for (int check = 1; check < (1 << N); check++) {
			sum = 0;
			/*
			��Ʈ����ũ���� �׷� 2�� �����̴ϱ�
			���� ch�� 0101�϶�,
			�ι��� ���� ����
			0�� ��Ʈ���� N�� ��Ʈ���� Ȯ���ϴµ�
			0�� ��Ʈ 1 / 1�� ��Ʈ 0 / 2����Ʈ 1
			�� H[0]�� H[2] �� sum�� �����شٴ� !! ����!
			*/

			//������ ���� ���� Ȯ�� -> ��Ʈ�� ���������� ��������.
			for (int i = 0; i < N; i++) 
				if (check&(1 << i)) 
					sum += H[i];


			//�հ谡 B���� ������ ���� Ȯ��
			if (sum > B)
				mi = MIN(mi, sum - B);//���̰� �� ���� �� ����
			//�հ谡 ��ǥ�� ������ �׳� break :0�� �ּ� �����̹Ƿ�
			if (sum == B)
			{
				mi = 0;
				break;
			}
		}
		cout << "#" << tc << " " << mi << endl;
	}
	return 0;
}



//(6/10����)
/*
#include <iostream>
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;

int N, B, rst;
int H[20];
bool flag[20];
int smallest = -1;

void smaller(int sum) {
	if (sum < B) return;
	else if (sum >= B) { // B���ݳ��̺��� ũ��,
		if (smallest<B)  //���� �������� ���̰� B���� ������
			smallest = sum;
		else rst = MIN(smallest, sum);
	}
}

void C(int n, int r) {
	if (n == r) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (flag[i] == 1)
				sum += H[i];
		}
		for (int i = 0; i < n; i++) {
			flag[i] = 0;
		}

		smaller(sum);
		return;
	}
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (flag[j] == 1)
					sum += H[j];
			}
			flag[i] = 0;
			smaller(sum);
		}

		return;
	}
	flag[n - 1] = 1;
	C(n - 1, r - 1);
	flag[n - 1] = 0;
	C(n - 1, r);
}
int main() {
	// cin,cout �ӵ����
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {

		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i]; //������ Ű �Է¹ޱ�
		}

		for (int j = 0; j < N; j++) {
			C(N, j + 1);//���� ���ϱ�
		}
		cout << "#" << tc << " " << rst - B << endl;
	}
	return 0;
}
*/


/*
//�ּ� ����
#include <iostream>
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;

int N, B, rst;
int H[20];
bool flag[20];
int min = -1;

void smaller(int sum) {
	if (sum < B) {
		return;
	}
	else if (sum >= B) { // B���ݳ��̺��� ũ��,
		if (min<B) { //���� �������� ���̰� B���� ������
			min = sum;
			//cout << "3" << endl;
			//cout << "min: " << sum << endl;
		}
		else {
			rst = MIN(min, sum);
			//cout << "4" << endl;
			//cout << "rst: " << rst << endl;
		}
	}
}

void C(int n, int r) {
	if (n == r) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (flag[i] == 1)
				sum += H[i];
		}
		//cout << "2" << endl;
		//cout << "sum: " << sum << endl;
		for (int i = 0; i < n; i++) {
			flag[i] = 0;
		}
		
		smaller(sum);
		return;
	}
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			flag[i] = 1;
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (flag[j] == 1)
					sum += H[j];
			}
			//cout << "1" << endl;
			//cout << "sum: " << sum << endl;
			flag[i] = 0;
			smaller(sum);
		}
		
		return;
	}
	flag[n - 1] = 1;
	C(n - 1, r - 1);
	flag[n - 1] = 0;
	C(n - 1, r);
}
int main() {
	// cin,cout �ӵ����
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {

		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i]; //������ Ű �Է¹ޱ�
		} 

		for (int j = 0; j < N; j++) {
			 C(N, j+1);
		}
		cout << "#" << tc << " " << rst - B << endl;
	}
	return 0;
}
*/


/*
//���� .. 
#include <iostream>
#define INF 987654321
#define MIN(x,y) (((x)<(y))?(x):(y))
using namespace std;
int N, B, rst;
int H[20];//20���� �������� ����.

void clerk_top(int s, int idx) {

	if (idx >= N) {
		if (s < B)return; //B���� ������ �ȵ�

		int min = s - B;

		//if()
	}
	//��������� �������� ž�� �ּҺ��� ũ�� ����..
	if (s >= rst) return;

	//�������� ž�� ���ݺ��� ũ��?
	else if (idx >= N) {
		if (s >= B && s < rst)
			rst = s;
		return;
	}

	//������ ���� 
	else {
		//idx�� ���� Ű ������ ����
		clerk_top(idx + 1, s);
		
		//idx�� ���� Ű ����
		clerk_top(idx + 1, s + H[idx]);
	}

} 

int main() {
	// cin,cout �ӵ����
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {

		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i]; //������ Ű �Է¹ޱ�
		}

		rst = INF; //�ϴ� ū �� �־���.
		clerk_top(0, 0);
		//int min = rst - B;
		//cout << "#" << tc << " " << min << endl;
	}
	return 0;
}
*/