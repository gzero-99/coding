//[����] #1759 ��ȣ �����
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
			bt(i + 1, ja, mo + 1, str + arr[i]);//�����̸� ..
		else
			bt(i + 1, ja + 1, mo, str + arr[i]);
	}
}
int main() {
	cin >> L >> C;
	
	//�Է� �ޱ�
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		arr[i] = c;
	}
	//������ ���� - ��������.. 
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
if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') //�����̸� ..
v.push_back(make_pair(c, true));
else
v.push_back(make_pair(c, false));
}
//������ ���ϴ� �Լ�
//������� ���ڿ� ���� queue�� �Է� ? �ƴϸ� �ٷιٷ� ��� .?
*/