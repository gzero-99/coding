
// [백준] # 1874 스택 수열 ♥
//사용 언어 : c++
#include<iostream>
#include<stack>
using namespace std;

int main() {
	int N,tmp;
	int arr[100001];
	char result[200002];
	bool p = true;
	stack <int >n,s,a,b;
	//a는 n에서 pop해서 push , b는 a에서 pop된 것들 push

	scanf("%d", &N);

	for(int i=N;i>0;i--) {
		scanf("%d",&tmp);
		arr[i-1] = tmp;
		n.push(i); // 기본 n부터 1까지의 stack 저장.
	}
	for(int k=0;k<N;k++) {
		s.push(arr[k]); //목표 스택의 반대 순서로 스택 저장.
	}

	int cnt = 0;
	while (1) {
		if (s.empty() == true )
			break;
		else {
			if (n.empty() == true && a.top() == s.top())
			{
				b.push(a.top());
				a.pop(); s.pop();
				result[cnt] = '-';
			}
			else if( n.empty() ==false){ //+도 가능함
				if (a.empty() == true) {//a가 비어있으면 ..+ 만 가능
					a.push(n.top());
					n.pop();
					result[cnt] = '+';//printf("+");
				}
				else if(a.empty()==false){ //a가 비어있지 않으면 ?
					if (n.top() != s.top() && a.top() != s.top())
					{//푸시해야할 목표값이 나올때까지 pop 시키기
						a.push(n.top());
						n.pop();
						result[cnt] = '+';//printf("+");
					}
					else if (n.top() == s.top()) { //해당 값이 나오면 
						a.push(n.top());
						n.pop(); s.pop();
						result[cnt] = '+'; cnt++;
						b.push(a.top());
						a.pop();
						result[cnt] = '-';//printf("-"); 
					}
					else if (a.top() == s.top() && n.top() != s.top()) {
						b.push(a.top());
						a.pop(); s.pop();
						result[cnt] = '-';
					}	
				}
			}
			else {
				p = false; 		//break하면서 no인 경우 p=false저장해주기.
				break;
			}
		}
		cnt++;
	}

	//출력 part
	if (p == true) {
		for (int j = 0; j < cnt; j++)
		{
			printf("%c", result[j]);
			if (j != cnt-1 )
				printf("\n");
		}
	}
	else
		printf("NO");

	return 0;
}
