/*
//������ #1107 c++ ������ [����] ��
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX 1000001
using namespace std;
int  goal, M;
vector <int> broken;

//2-1.**ä�� ������ ����? �Ұ���? 
//���峭 ��ư ������ false
bool press_button(int x) {
	if (x == 0) {
		//algorithm vector�� find�Լ�
		//ù��°�� ��ġ�ϴ� ���Ҹ� ����Ű�� �ݺ���, 
		//��ġ�ϴ¿��Ұ� ���� ��� last�� ���ϵ� [first, last]
		if (find(broken.begin(), broken.end(), 0) == broken.end())
			return true;
		else
			return false;
	}
	while (x) {
		if (find(broken.begin(), broken.end(), x % 10) != broken.end())
			return false;
		x /= 10;
	}
	return true;
}


int main() {
	cin >> goal >> M;

	//���峭 ��ư M�� �Է¹ޱ�.
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		broken.push_back(b);
	}

	//1. ���� ä���� 100���� +,-�� �ٲٴ� ���
	int hundred = abs(goal - 100);
	
	//2. ���ڹ�ư�� ������ ä���� �Է��� �� +,-�� �ٲٴ°��
	int press_num;
	int after = 9999999, before = 0;
	for (int i = 0; i < MAX; i++) {//���Ʈ ����:0���� �����ϰ�!

		//ä�� ������ ����
		if (press_button(i) == true) {
			int press = abs(goal - i);//+,- ��� �������� Ȯ��
			if (after > press)//2-2. �� ������ �Ǹ�?
			{
				after = press;
				before = i; //�ش� ���� ����
			}
		}
	}
	//2-3. ���� ä���� �ڸ��� ���ϱ�
	int digit = 0; 
	if (before == 0)
		digit = 1;
	else {
		while (before) {
			before /= 10;
			digit++;
		}
	}
		
	//3. ��� ���ϱ� :  �ΰ� ��� �� �ּڰ�
	press_num = after + digit;
	cout << MIN(hundred, press_num) << endl;

	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
bool button[10];
//int channel[6];
int c, goal, M;
vector <int> num;
vector <int> num2;
int cur = 100;
int cnt = 0;



//���� ���ؼ� 0~9�� 1�� �ƴ� ��ư�� �������� �Ѵ�.

int compare_num(int x) {
		int add = x + 1;
		int minus = x - 1;
		//if (add<=9 && minus >=0) { //��ȣ�� �´¾ָ�,
		//}
		if (add > 9)
			add = 0;
		else if (minus < 0)
			minus = 9;

		if (button[add] == 0) { //+ �ߴ��� �ִ� ��ư�̸�? �� ��ư �ϳ� �߰�
			return add;
		}
		else if (button[minus] == 0) {// - �ߴ��� �ִ� ��ư �� ��ư �ϳ� �߰�
			return minus;
		}
		else { //�Ѵ� �ִ� ��ư�� �ƴϸ� ?
			compare_num(add);
			compare_num(minus);
			//�� ���� ���� ���ϵż� �������� ?
		}
}

int main() {
	cin >> c >> M;
	goal = c;//��ǥ ä��

	int a = 0;
	while (c != 0) {
		num.push_back( c % 10); //���ڸ����� ���ڸ��� �и� ����.
		c /= 10;
		a++;
	}
	reverse(num.begin(), num.end());//���ڸ����ͷ� ���� ����.

	//���峭 ��ư M�� �Է¹ޱ�.
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		button[b] = 1;//���峭 ��ȣ�� 1�� ����.
	}
	

	vector<int>::iterator iter;
	for (iter = num.begin(); iter != num.end(); iter++) {
		if (button[*iter] == 0) {
			//���� ���峭 ��ȣ�� �ƴ϶��, �� ��ȣ �Է� ������ ��.
			cnt++;//�ش� ��ư�� ������. Ƚ�� �߰�
			//continue;
			num.push_back(*iter);
		}
		else if (button[*iter] == 1) {
			//���� ���峭 ��ȣ��?
			//int cm = compare_num(*iter);
			//cnt = cm;
			int cm = compare_num(*iter); //��ư �Ѱ� �� ����.
			cnt++;
			
			//if (cm > *iter)
				//cnt = cnt + cm - *iter;
			//else if (cm < *iter)
				//cnt = cnt + *iter - cm;
			

			
			break; 
		}

		//cout << *iter << " ";
	}
	//cout << endl << endl;

	int rst;
	
	//���⼭ 
	//���� ä���� 100�� ���ؼ� ������ �� 
	//�̰Ŷ����ؼ� ���� cnt ���̶� ���ؼ� �� ���� ���� rst�� ���.

	return 0;
}
*/

/*
1. 100���� + -�� ������.
2. ���ڸ� ������ + -�Ѵ�
*/

/*
//���� ���ؼ� 0~9�� 1�� �ƴ� ��ư�� �������� �Ѵ�.
int compare_num(int x) {
int add = x + 1;
int minus = x - 1;
//if (add<=9 && minus >=0) { //��ȣ�� �´¾ָ�,
//}
if (add > 9)
add = 0;
else if (minus < 0)
minus = 9;

if (button[add] == 0) { //+ �ߴ��� �ִ� ��ư�̸�?
return cnt++;
}
else if (button[minus] == 0) {// - �ߴ��� �ִ� ��ư
return cnt++;
}
else { //�Ѵ� �ִ� ��ư�� �ƴϸ� ?

int a = compare_num(add);
int m = compare_num(minus);
if (a < m)
return a;
else if (a > m)
return m;
else return a;
}
}
*/


/*
int main() {
	vector <int> vb;
	int channel;//��ǥ ä��
	int cur = 100;//���� ä�� 
	int M; //������ ��ư ����
	cin >> channel >> M;
	for (int i = 0; i < 10-M; i++) {
		//v.push_back(make_pair(i, 0));
		vb.push_back(0);
	}
	for (int i = 0; i < M; i++) {
		int button;
		cin >> button; //������ ��ư �Է�
		vb.insert(button, 1, 1);

	}

	return 0;
}*/