
//������ [SW] # 1206 c++ view ��
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
//������ [SW] # 1206 c++ view ��
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
	if (idx == 3 || checked == false) { // 1,2 �� 0 ���� ä���� .
		if (bd[idx - 2] >= bd[idx - 1])
			fBig = bd[idx - 2];
		else
			fBig = bd[idx - 1];

		if (bd[idx + 1] >= bd[idx + 2])
			bBig = bd[idx + 1];
		else
			bBig = bd[idx + 2];
	}
	else if (idx <= TC - 2) {  // TC �� 1000�̶�� 1000,999�� 0���� ä����.
		fBig = bBig; // ���� ū ���� ���� ���� ū ������ �ٲ��ֱ�.
		checked = false; // true�̸� 
		if (bd[idx + 1] >= bd[idx + 2])
			bBig = bd[idx + 1];
		else
			bBig = bd[idx + 2];
	}

	if (fBig >=now|| bBig >=now) // ���� ���� �� ���� ū ������ �۴ٸ� ?
		 riverViewCnt(idx + 1, cnt ,false);
	// ���� ���� �� �� ������ ũ�ٸ� ?
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
// �պκ��� ���� ���� ���ְ� ������ ��,,, �̸� ����Ȱ� �ٽþ��� �Ǵ� ���ݾ� ..
if (idx == 3 && TC>5) {
if (bd[idx - 2] >= bd[idx - 1])
fBig = bd[idx - 2];
else if (bd[idx - 1] > bd[idx - 2]) // else
fBig = bd[idx - 1];
if (fBig >= bd[idx]) //���� ū ���� ���簪���� Ŭ ���
return riverViewCnt(idx + 1);
else {
if (bd[idx + 1] >= bd[idx + 2])
bBig = bd[idx + 1];
else
bBig = bd[idx + 2];

if (bBig >= bd[idx]) // �ڿ� ū ���� ���簪���� Ŭ ���
return riverViewCnt(idx + 1);
else if (bBig >= fBig) // ���簪�� ��, �� ������ ũ�� ,�յ�ū���߿� �� ū�� �� ���� ���ϱ� .
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
// ������� , �յڰ��� ū ���� ���ؼ� �����صΰ� ...?
//�Ź� �ݺ��ϸ鼭 �ڿ� ���� ���� ū ������ �׳� ����ϰ� , �ڿ� ū ���� �ٽ� �����ֱ� .
}
*/

