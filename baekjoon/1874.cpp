
// [����] # 1874 ���� ���� ��
//��� ��� : c++
#include<iostream>
#include<stack>
using namespace std;

int main() {
	int N,tmp;
	int arr[100001];
	char result[200002];
	bool p = true;
	stack <int >n,s,a,b;
	//a�� n���� pop�ؼ� push , b�� a���� pop�� �͵� push

	scanf("%d", &N);

	for(int i=N;i>0;i--) {
		scanf("%d",&tmp);
		arr[i-1] = tmp;
		n.push(i); // �⺻ n���� 1������ stack ����.
	}
	for(int k=0;k<N;k++) {
		s.push(arr[k]); //��ǥ ������ �ݴ� ������ ���� ����.
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
			else if( n.empty() ==false){ //+�� ������
				if (a.empty() == true) {//a�� ��������� ..+ �� ����
					a.push(n.top());
					n.pop();
					result[cnt] = '+';//printf("+");
				}
				else if(a.empty()==false){ //a�� ������� ������ ?
					if (n.top() != s.top() && a.top() != s.top())
					{//Ǫ���ؾ��� ��ǥ���� ���ö����� pop ��Ű��
						a.push(n.top());
						n.pop();
						result[cnt] = '+';//printf("+");
					}
					else if (n.top() == s.top()) { //�ش� ���� ������ 
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
				p = false; 		//break�ϸ鼭 no�� ��� p=false�������ֱ�.
				break;
			}
		}
		cnt++;
	}

	//��� part
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
