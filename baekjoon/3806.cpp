//Baekjoon g0 #3806 S to T ♥

#include <iostream>
#include <string>
#define MAX 101
using namespace std;
int main() {
	int TC;
	string S, T;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> S >> T;
		int  Sqcnt = 0,t1 = 0;//? 문자열 개수 ,  다른 부분 중 t문자열 1의 개수
		int s0 = 0, s1 = 0; // s와 t문자열 비교했을대, 다른 부분 중 s문자열의 문자개수.
		int rst = 0;
		int Tnum[MAX];	//t문자열 저장. s문자열과 비교시 사용.

		int k = 0;
		for (string::iterator iter = T.begin(); iter != T.end(); ++iter) {
			char c = *iter;
			Tnum[k] = c - '0';
			k++;
		}
		k = 0;
		for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
			char c = *iter;
			if (Tnum[k] != (c-'0')) { //s와 t 문자열 다른 부분
				if (Tnum[k] == 1)
					t1++; //1이필요한데, s에 ?나 0이 있는 경우.

				if (*iter == '0')
					s0++;	//s가 0일때, 0->1이나 교환가능 
				else if (*iter == '1')
					s1++;	//s가 1일때, 교환해줘야함 
				else
					Sqcnt++; //? 일 때 (무조건 0이나 1로 )
			}
			k++;
		}
		//** s문자열에서 가능한 작업 0->1 , ? ->1 , ? ->0 , 0<->1(교환)

		if (s0 + s1 + Sqcnt != 0) { //s랑 t에 다른 부분이 있으면
			if (s1 > t1) //s랑 t가 다른 부분 중에서도, s의 1의 개수 > t의 1의 개수면 -1 출력 1->0불가능잉게.
				rst = -1;
			else {
				if (s0 == s1)	
					rst = s1 + Sqcnt;
				else if (s0 < s1) // s1이 더 크면 s1더해주기
					rst = s1 + Sqcnt;
				else			//s0이 더 크면 s0더해주기.
					rst = s0 + Sqcnt;
			} //0<->1 교환 (s0 혹은 s1) / 그리고 남은것들은 ?로 바꿔주는 것 (Sqcnt) = 최소 연산의 수 
			
		}
		//output
		cout << "Case " << i << ": " << rst << endl;
	}
	return 0;
}


/*
#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int main()
{
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		int rst = 0;
		int S0cnt = 0, S1cnt = 0, Sqcnt = 0, T0cnt = 0, T1cnt = 0;
		string S, T;
		cin >> S;
		cin >> T;
		int Tnum[MAX];
		int k = 0;
		for (string::iterator iter = T.begin(); iter != T.end(); ++iter) {
			if (*iter == '0')
				T0cnt++;
			else if (*iter == '1')
				T1cnt++;
			char c = *iter;
			Tnum[k] = c - '0';
			k++;
		}
		k = 0;
		int s0 = 0, s1 = 0;
		for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
			if (*iter == '0') {
				S0cnt++;
				if (Tnum[k] != 0)  //위치가 다르면 추가해줌 ..//1이 필요한데, 0이 있을때
					s0++;
			}
			else if (*iter == '1') {
				S1cnt++;
				if (Tnum[k] != 1) //0이 필요한데 1이 있을때,
					s1++;
			}
			else  //?의 경우
				Sqcnt++;
			k++;
		}

		if (Sqcnt == 0 && S0cnt < T0cnt ) //?가 없을때,s: 1->0은 불가능 (T0cnt가 S0cnt보다 많으면 아웃)
			rst = -1;
		else if (Sqcnt==0 && S1cnt <=T1cnt) {//?가 없을 때 ,s: 0->1은 가능 .. 
			rst += T1cnt-S1cnt; //t와 다른 0의 개수만큼  바꿔줌 .
			int tmp = rst;
			//그리고 위치 바꾸는건 ..?
			rst += s0 - tmp;
		}
		else {//?가 있는 상태.
			//?부분을 0또는 1로 바꿔줄수있음. (s를 t에 맞게 알아서 바꾸면 됨) //rst += Sqcnt;
			//다만! 0->1해서 1의 개수는 늘릴수있지만 . 0의 개수는 늘릴수없으므로! 0의 개수를 비교파악해서 부족한 만큼 ?에서 만들어줘야함 
			int zero, one;
			if (S0cnt < T0cnt) { //필요한 0의 개수가 존재하는 0의 개수보다 많으면 . ?로 0을 만들어줘야함 ..
				if (Sqcnt < T0cnt) { //필요한0의 개수가?보다 많으면 
					rst = -1; //안됨
					}
				else {
					zero = Sqcnt - S0cnt;//? ->0
					rst += zero;
					if (S1cnt < T1cnt) {//필요한 1의 개수가 더 많을때 ..
						if (Sqcnt -zero> T1cnt) {
							one = T1cnt;
							rst += one;
						}
						else { //?보다 1이 더 많이 필요하면 ..
							//0->1해줘야해 !
							//if (s0 >= ) {
								//ㅅㅂ ..
							//}
						}
					}
				}
				//?를 그 개수만큼 0으로 만들어준다
				//rst += T0cnt - S0cnt;
				//int tmp = rst;
				//남은 ?는 1로 만들어준다
				//rst += Sqcnt - tmp;

			}
			else if (S0cnt > T0cnt) {//필요한 0의 개수가 존재하는 0의 개수보다 적으면 .. 0->1해줘야함
				if (Sqcnt > s0) {
					rst = -1; //? 개수보다 필요한 0의 개수가 많으면. 불가능
				}
				else {
					one = Sqcnt - s0;//1로 바꿀수있는 남은 ?의 개수
					rst += s0;
					if (S1cnt < T1cnt) {
						rst += one; //일단 남은 ? 개수만큼 바꿔주고.
						zero = 0;
						//위치 다른거 더해주는거는 마지막에!
					}

				}

			}


			if (rst == -1) {

			}
			else {

			}

			//예전
			if (S0cnt < T0cnt)
				zero = T0cnt - S0cnt;
			else if (S0cnt > T0cnt) {
				zero = S0cnt - T0cnt;
			}
			else if (S0cnt == T0cnt)
				zero = 0;

			if (S1cnt < T1cnt)
				one = T1cnt - S1cnt;
			else if (S1cnt > T1cnt)
				one = S1cnt - T1cnt;
			else
				one = 0;

			if (zero + one != Sqcnt)
				rst = -1; //부족한 거 개수가 다르면 안됨
			else
				rst += Sqcnt; //?가 0이나 1로 변할 개수 더해주고.

							  //?가 있는 곳을 0과 1로 변환해준거 더해줬음
							  //이제 ?가 있는 곳에 입력된것과 다른 위치의 것들을 찾아 더해줘야함.
			k = 0;
			for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
				if (*iter == '?') { //?의 경우
									//0이 필요하고, 0이 남은경우
									//cout << "Tnum["<<k<<"] : "<<Tnum[k]<<endl;
					if (Tnum[k] == 0 && zero > 0) {
						zero--;
					}
					//0이 필요하지만,0 이 없는 경우,1을 넣음
					else if (Tnum[k] == 0 && zero == 0) {
						one--;
						s1++;
					}
					//1이 필요하고, 1이 남은경우
					else if (Tnum[k] == 1 && one > 0) {
						one--;
					}
					//1이 필요하고, 1이 없는 경우 , 0을 넣음
					else if (Tnum[k] == 1 && one == 0) {
						zero--;
						s0++;
					}
				}
				k++;
			}
			rst += s0; // 최종 s0랑 s1의 개수는 무조건 같아야함 ..



		}//?가 있는 상태 끝.

		 //output
		//cout << "Case " << i << ": " << rst << endl;
		
	}
	return 0;
}
*/

//Baekjoon g0 #3806 S to T ♡ - 조건 자체를 잘못함 

/*
#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int main()
{
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		int rst = 0;
		int S0cnt = 0, S1cnt = 0, Sqcnt = 0, T0cnt = 0, T1cnt = 0;
		string S, T;
		cin >> S;
		cin >> T;
		int Tnum[MAX];

		int k = 0;
		for (string::iterator iter = T.begin(); iter != T.end(); ++iter) {
			if (*iter == '0') 
				T0cnt++;
			else if (*iter == '1') 
				T1cnt++;
			char c = *iter;
			Tnum[k] = c - '0';
			k++;
		}
		k = 0;
		int s0 = 0, s1 = 0;
		for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
			if (*iter == '0') {
				S0cnt++;
				if (Tnum[k] != 0)  //위치가 다르면 추가해줌 ..//1이 필요한데, 0이 있을때
					s0++;
			}
			else if (*iter == '1') {
				S1cnt++;
				if (Tnum[k] != 1) //0이 필요한데 1이 있을때,
					s1++;
			}
			else  //?의 경우
				Sqcnt++;
			k++;
		}

		if (Sqcnt == 0 && (S0cnt != T0cnt || S1cnt != T1cnt))
			rst = -1;
		else if (Sqcnt == 0 && (S0cnt == T0cnt && S1cnt == T1cnt)) {
			//?도 없고, 0과1의 개수가 같은경우
			//다른 위치에 있는지만 확인하면 됨
			if (s0 == s1) 
				rst += s0; //위치 교환해줄 애들
		}
		else {//?가 있는 상태.
			int zero, one;
			if (S0cnt < T0cnt) 
				 zero = T0cnt - S0cnt;
			else if (S0cnt > T0cnt) {
				zero = S0cnt - T0cnt;
			}
			else if (S0cnt == T0cnt) 
				zero = 0;

			if (S1cnt < T1cnt)
				one = T1cnt - S1cnt;
			else if (S1cnt > T1cnt)
				one = S1cnt - T1cnt;
			else
				one = 0;

			if (zero + one != Sqcnt)
				rst = -1; //부족한 거 개수가 다르면 안됨
			else
				rst += Sqcnt; //?가 0이나 1로 변할 개수 더해주고.

			//?가 있는 곳을 0과 1로 변환해준거 더해줬음
			//이제 ?가 있는 곳에 입력된것과 다른 위치의 것들을 찾아 더해줘야함.
			k = 0;
			for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
				if (*iter =='?'){ //?의 경우
					//0이 필요하고, 0이 남은경우
					//cout << "Tnum["<<k<<"] : "<<Tnum[k]<<endl;
					if (Tnum[k] == 0 && zero > 0) {
						zero--;
					}
					//0이 필요하지만,0 이 없는 경우,1을 넣음
					else if (Tnum[k] == 0 && zero == 0) {
						one--;
						s1++;
					}
					//1이 필요하고, 1이 남은경우
					else if (Tnum[k] == 1 && one > 0) {
						one--;
					}
					//1이 필요하고, 1이 없는 경우 , 0을 넣음
					else if (Tnum[k] == 1 && one == 0) {
						zero--;
						s0++;
					}
				}
				k++;
			}
			rst += s0; // 최종 s0랑 s1의 개수는 무조건 같아야함 ..

		}//?가 있는 상태 끝.


		//output
		cout << "Case " << i << ": " << rst;
	}
	return 0;
}
*/