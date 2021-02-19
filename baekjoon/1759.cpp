//[백준] #1759 암호 만들기
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int L, C;
char arr[16]; // 3<=L<=C<=15

void bt(int fi, int ja, int mo, string str) {
	if (str.size() == L) {
		if (ja < 2 || mo < 1)
			return;
		
		cout << str << endl;
	}
	for (int i = fi; i < C; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') 
			bt(i + 1, ja, mo + 1, str + arr[i]);//모음이면 ..
		else
			bt(i + 1, ja + 1, mo, str + arr[i]);
	}
}
int main() {
	cin >> L >> C;
	
	//입력 받기
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		arr[i] = c;
	}
	//사전식 나열 - 오름차순.. 
	sort(arr, arr + C);
	bt(0, 0, 0, "");

	return 0;
}

/*
vector <pair<char, bool>>v;
string str2;
string rst;
for (int i = 0; i < C; i++) {
str2.append(1,str[i]);
char c = str[i];
if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') //모음이면 ..
v.push_back(make_pair(c, true));
else
v.push_back(make_pair(c, false));
}
//사전식 비교하는 함수
//순서대로 문자열 만들어서 queue에 입력 ? 아니면 바로바로 출력 .?
*/