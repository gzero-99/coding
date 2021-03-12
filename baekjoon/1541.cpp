//백준 1541  잃어버린 괄호 
#include <iostream>
#include <string>
using namespace std;

string str = "";

int main() {
	cin >> str;
	int rst = 0;
	bool minus = false; //뺄셈인지 확인용
	string num = ""; //피연산자 저장

	for (int i = 0; i <= str.size(); i++) {
		//연산자 만나면 
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus == true)
				rst -= stoi(num); //숫자 빼기
			else
				rst += stoi(num); //숫자 더하기

			num = "";//초기화해주고,
			//괄호는 뺄셈일때 부터~쳐주면 됨
			if (str[i] == '-')
				minus = true;
			continue;
		}
		//피연산자라면
		num += str[i];
	}
	cout << rst;
	return 0;
}