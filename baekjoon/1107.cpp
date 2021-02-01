/*
//장지영 #1107 c++ 리모컨 [백준] ♥
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX 1000001
using namespace std;
int  goal, M;
vector <int> broken;

//2-1.**채널 누르기 가능? 불가능? 
//고장난 버튼 누르면 false
bool press_button(int x) {
	if (x == 0) {
		//algorithm vector의 find함수
		//첫번째로 일치하는 원소를 가리키는 반복자, 
		//일치하는원소가 없는 경우 last가 리턴됨 [first, last]
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

	//고장난 버튼 M개 입력받기.
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		broken.push_back(b);
	}

	//1. 현재 채널인 100에서 +,-로 바꾸는 경우
	int hundred = abs(goal - 100);
	
	//2. 숫자버튼을 눌러서 채널을 입력한 후 +,-로 바꾸는경우
	int press_num;
	int after = 9999999, before = 0;
	for (int i = 0; i < MAX; i++) {//브루트 포스:0부터 무식하게!

		//채널 누르기 가능
		if (press_button(i) == true) {
			int press = abs(goal - i);//+,- 몇번 누르는지 확인
			if (after > press)//2-2. 덜 눌러도 되면?
			{
				after = press;
				before = i; //해당 숫자 저장
			}
		}
	}
	//2-3. 누른 채널의 자릿수 구하기
	int digit = 0; 
	if (before == 0)
		digit = 1;
	else {
		while (before) {
			before /= 10;
			digit++;
		}
	}
		
	//3. 결과 구하기 :  두개 경로 중 최솟값
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



//숫자 비교해서 0~9중 1이 아닌 버튼을 누르도록 한다.

int compare_num(int x) {
		int add = x + 1;
		int minus = x - 1;
		//if (add<=9 && minus >=0) { //번호에 맞는애면,
		//}
		if (add > 9)
			add = 0;
		else if (minus < 0)
			minus = 9;

		if (button[add] == 0) { //+ 했더니 있는 버튼이면? 그 버튼 하나 추가
			return add;
		}
		else if (button[minus] == 0) {// - 했더니 있는 버튼 그 버튼 하나 추가
			return minus;
		}
		else { //둘다 있는 버튼이 아니면 ?
			compare_num(add);
			compare_num(minus);
			//이 둘중 먼저 리턴돼서 나오겠지 ?
		}
}

int main() {
	cin >> c >> M;
	goal = c;//목표 채널

	int a = 0;
	while (c != 0) {
		num.push_back( c % 10); //뒷자리부터 한자리씩 분리 가능.
		c /= 10;
		a++;
	}
	reverse(num.begin(), num.end());//앞자리부터로 순서 변경.

	//고장난 버튼 M개 입력받기.
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		button[b] = 1;//고장난 번호면 1로 변경.
	}
	

	vector<int>::iterator iter;
	for (iter = num.begin(); iter != num.end(); iter++) {
		if (button[*iter] == 0) {
			//만약 고장난 번호가 아니라면, 그 번호 입력 받으면 됨.
			cnt++;//해당 버튼을 눌렀음. 횟수 추가
			//continue;
			num.push_back(*iter);
		}
		else if (button[*iter] == 1) {
			//만약 고장난 번호면?
			//int cm = compare_num(*iter);
			//cnt = cm;
			int cm = compare_num(*iter); //버튼 한개 더 누름.
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
	
	//여기서 
	//현재 채널인 100과 비교해서 나오는 값 
	//이거랑위해서 구한 cnt 값이랑 비교해서 더 작은 값이 rst로 출력.

	return 0;
}
*/

/*
1. 100부터 + -로 누른다.
2. 숫자를 누르고 + -한다
*/

/*
//숫자 비교해서 0~9중 1이 아닌 버튼을 누르도록 한다.
int compare_num(int x) {
int add = x + 1;
int minus = x - 1;
//if (add<=9 && minus >=0) { //번호에 맞는애면,
//}
if (add > 9)
add = 0;
else if (minus < 0)
minus = 9;

if (button[add] == 0) { //+ 했더니 있는 버튼이면?
return cnt++;
}
else if (button[minus] == 0) {// - 했더니 있는 버튼
return cnt++;
}
else { //둘다 있는 버튼이 아니면 ?

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
	int channel;//목표 채널
	int cur = 100;//현재 채널 
	int M; //망가진 버튼 개수
	cin >> channel >> M;
	for (int i = 0; i < 10-M; i++) {
		//v.push_back(make_pair(i, 0));
		vb.push_back(0);
	}
	for (int i = 0; i < M; i++) {
		int button;
		cin >> button; //망가진 버튼 입력
		vb.insert(button, 1, 1);

	}

	return 0;
}*/