
//#10824 Ω∫≈√ 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N, X;
	string str;
	stack <int> s;
	scanf("%d", &N);

	while (N > 0) {
		cin >> str;
		if (str.compare("push") == 0) {
			scanf("%d", &X);
			s.push(X);
		}
		else if (str.compare("pop") == 0) {
			if (s.empty() == true)
			{
				printf("-1");
			}
			else {
				printf("%d", s.top());
				s.pop();
			}
			if (N > 1)printf("\n");
		}
		else if (str.compare("size") == 0) {
			printf("%d", s.size());
			if (N > 1)printf("\n");
		}
		else if (str.compare("empty") == 0) {
			if (s.empty() == true)
				printf("1");
			else
				printf("0");
			if (N > 1)printf("\n");
		}
		else if (str.compare("top") == 0) {
			if (s.empty() == true)
				printf("-1");
			else printf("%d", s.top());
			if (N > 1)printf("\n");
		}
		
		N--;
	}
	return 0;
}
