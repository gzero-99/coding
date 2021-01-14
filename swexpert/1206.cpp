
//장지영 [SW] # 1206 c++ view ♥
#include <iostream>
#include <stdbool.h>
#define MAX(a,b) a>=b?a:b
using namespace std;
int TC;
int bd[1002];
int haveView = 0;
bool checked = false;
int fBig, bBig, now;
void riverViewCnt(int idx, int cnt, bool ck) {
	checked = ck;
	now = bd[idx];
	if (idx > TC - 2)
	{
		haveView = cnt;
		return;
	}
	if (idx == 3 || checked == false) {
		fBig = MAX(bd[idx - 2], bd[idx - 1]);
		bBig = MAX(bd[idx + 1], bd[idx + 2]);
	}
	else if (idx <= TC - 2) {
		fBig = bBig;
		checked = false; // if true
		bBig = MAX(bd[idx + 1], bd[idx + 2]);
	}

	if (fBig >= now || bBig >= now)
		riverViewCnt(idx + 1, cnt, false);
	else if (bBig >= fBig)
		riverViewCnt(idx + 3, cnt + (now - bBig), true);
	else if (fBig > bBig)
		riverViewCnt(idx + 3, cnt + (now - fBig), true);

}
int main() {
	int i = 1;
	while (i <= 10) {
		scanf_s("%d", &TC);
		haveView = 0;
		if (TC > 1000)
			break;
		bd[0] = 0;
		for (int j = 1; j <= TC; j++) {
			scanf_s("%d", &bd[j]);
		}
		riverViewCnt(3, 0, false);
		printf("#%d %d\n", i, haveView);
		i++;
	}

	return 0;
}

/*
//장지영 [SW] # 1206 c++ view ♥
#include <iostream>
#include <stdbool.h>
using namespace std;
int TC;
int bd[1002];
int haveView = 0;
bool checked = false;
int fBig, bBig, now;
void riverViewCnt(int idx, int cnt, bool ck) {
	checked = ck;
	now = bd[idx];
	if (idx > TC - 2)
	{
		haveView = cnt;
		return;
	}
	if (idx == 3 || checked == false) {
		if (bd[idx - 2] >= bd[idx - 1])
			fBig = bd[idx - 2];
		else
			fBig = bd[idx - 1];

		if (bd[idx + 1] >= bd[idx + 2])
			bBig = bd[idx + 1];
		else
			bBig = bd[idx + 2];
	}
	else if (idx <= TC - 2) {
		fBig = bBig;
		checked = false; // true 
		if (bd[idx + 1] >= bd[idx + 2])
			bBig = bd[idx + 1];
		else
			bBig = bd[idx + 2];
	}

	if (fBig >= now || bBig >= now)
		riverViewCnt(idx + 1, cnt, false);
	else if (bBig >= fBig)
		riverViewCnt(idx + 3, cnt + (now - bBig), true);
	else if (fBig > bBig)
		riverViewCnt(idx + 3, cnt + (now - fBig), true);

}
int main() {
	int i = 1;
	while (i <= 10) {
		scanf("%d", &TC);
		haveView = 0;
		if (TC > 1000)
			break;
		bd[0] = 0;
		for (int j = 1; j <= TC; j++) {
			scanf("%d", &bd[j]);
		}
		riverViewCnt(3, 0, false);
		printf("#%d %d\n", i, haveView);
		i++;
	}

	return 0;
}
*/
/*
#include <iostream>
#include <stdbool.h>
using namespace std;
int TC;
int bd[1002];
int haveView = 0;
bool checked = false;
int fBig, bBig, now;
void riverViewCnt(int idx, int cnt, bool ck) {
	checked = ck;
	now = bd[idx];
	if (idx > TC - 2)
	{
		haveView = cnt;
		return;
	}
	if (idx == 3 || checked == false) { // 1,2 는 0 으로 채워짐 .
		if (bd[idx - 2] >= bd[idx - 1])
			fBig = bd[idx - 2];
		else
			fBig = bd[idx - 1];

		if (bd[idx + 1] >= bd[idx + 2])
			bBig = bd[idx + 1];
		else
			bBig = bd[idx + 2];
	}
	else if (idx <= TC - 2) {  // TC 가 1000이라면 1000,999는 0으로 채워짐.
		fBig = bBig; // 뒤의 큰 값은 이제 앞의 큰 값으로 바꿔주기.
		checked = false; // true이면 
		if (bd[idx + 1] >= bd[idx + 2])
			bBig = bd[idx + 1];
		else
			bBig = bd[idx + 2];
	}

	if (fBig >=now|| bBig >=now) // 현재 값이 앞 뒤의 큰 값보다 작다면 ?
		 riverViewCnt(idx + 1, cnt ,false);
	// 현재 값이 앞 뒤 값보다 크다면 ?
	else if (bBig >= fBig) 
	{
		riverViewCnt(idx + 3, cnt + (now - bBig), true);
	}
	else if (fBig > bBig)
	{
		riverViewCnt(idx + 3, cnt + (now - fBig), true);
	}

}
int main() {
	int i = 1;
	while (i <= 10) {
		scanf_s("%d", &TC);
		haveView = 0;
		if (TC > 1000)
			break;
		bd[0] = 0;
		for (int j = 1; j <= TC; j++) {
			scanf_s("%d", &bd[j]);
			//if (bd[j] > 255 || bd[j] < 0)
		}
		riverViewCnt(3, 0 , false);
		printf("#%d %d\n", i, haveView);
		i++;
	}

	return 0;
}
*/

/*
// 앞부분은 따로 빼서 해주고 싶은ㄷ ㅔ,,, 미리 저장된거 다시쓰면 되는 거잖아 ..
if (idx == 3 && TC>5) {
if (bd[idx - 2] >= bd[idx - 1])
fBig = bd[idx - 2];
else if (bd[idx - 1] > bd[idx - 2]) // else
fBig = bd[idx - 1];
if (fBig >= bd[idx]) //앞의 큰 값이 현재값보다 클 경우
return riverViewCnt(idx + 1);
else {
if (bd[idx + 1] >= bd[idx + 2])
bBig = bd[idx + 1];
else
bBig = bd[idx + 2];

if (bBig >= bd[idx]) // 뒤에 큰 값이 현재값보다 클 경우
return riverViewCnt(idx + 1);
else if (bBig >= fBig) // 현재값이 앞, 뒤 값보다 크고 ,앞뒤큰값중에 더 큰값 뺀 값을 더하기 .
{
cnt = cnt + (bd[idx] - bBig);
return riverViewCnt(idx + 3);
}
else if (fBig > bBig)
{
cnt = cnt + (bd[idx] - fBig);
return riverViewCnt(idx + 3);
}
}
// 상관없이 , 앞뒤값의 큰 값을 구해서 저장해두고 ...?
//매번 반복하면서 뒤에 값은 앞의 큰 값으로 그냥 사용하고 , 뒤에 큰 값은 다시 구해주기 .
}
*/

