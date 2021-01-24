
//장지영 #2667 백준 단지번호 붙이기 c++ ♥
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[26][26]; // 5<=n<=25임
bool checked[26][26];
int danji[626]; // 25*25 가 최대임 
int scnt;
int n;
void find_danji_ofhome(int x, int y, int dcnt, int hcnt) {
	int xx, yy;
	int gxy;

	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (scnt > hcnt) { //집의 개수 큰 거로 넣어주기,
			hcnt = scnt;
		}
		danji[dcnt] = hcnt; //중요
		if (xx < 0 || xx > n - 1 || yy < 0 || yy > n - 1)continue;
		if (checked[xx][yy] == true) continue;

		
		//상하좌우 이동이 칸을 벗어나지 않으면 ?
		gxy = arr[xx][yy];
		checked[xx][yy] = true;
		if (gxy == 0 && i == 3) { //상하좌우 다 보고, 0이면  이동 그만 ..
			return;
		}
		else if (gxy == 1) {
			scnt = hcnt + 1;
			find_danji_ofhome(xx, yy, dcnt, hcnt + 1);
		}  
	}
}

int main() {
	int dcnt = 0;// 단지idx +1 해줄때 사용.
	scanf_s("%d", &n);

	//1. 지도에 집 입력받기 (띄어쓰기 없이 정수형 입력)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			scanf_s("%1d", &arr[i][j]);

	//2. 2차원 배열에 저장된 수 중에서,
	//1이 끊기지 않고 이어지는 경우 하나의 단지로 취급해준다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checked[i][j] == false) { 
				checked[i][j] = true;

				if (arr[i][j] == 0) //0이면 checked하고 넘어감
					continue;
				else if (arr[i][j] == 1) {
					//3. 1이면 단지 탐색 시작! 
					dcnt += 1;
					find_danji_ofhome(i, j, dcnt, 1);
					scnt = 0;
				}
			}
			else  continue;
		}
	}

	//4.순서대로 출력하기 위해 sort시킴
	int size = sizeof(danji) / sizeof(danji[0]);
	sort(danji, danji + size);

	printf("%d\n", dcnt);
	//5. 출력은 단지 배열을 sort시켜서 단지에 속하는 집의 수를 출력함
	for (int i = 0; i < size; i++) {
		if (danji[i] != 0) {
			printf("%d\n", danji[i]);
		}
	}
	return 0;
}


/*
// 히힛 출력했다!! 
#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[26][26]; // 5<=n<=25임
bool checked[26][26];
int danji[626]; // 25*25 가 최대임 
//int homes = 0;
int scnt;
int n;
// 1을 만났을때 돌려주고, 단지 내의 집들을 다 찾을때까지 돌려줌 .
void find_danji_ofhome(int x,int y, int dcnt, int hcnt) {
	int xx, yy;
	int gxy;
	
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (scnt > hcnt) {
			hcnt = scnt;
		}
		if (xx < 0 || xx > n-1 || yy < 0 || yy > n-1)continue;
		if (checked[xx][yy] == true) continue;
		//상하좌우 이동이 칸을 벗어나지 않으면 ?
		//이동한 점의 배열이
		gxy = arr[xx][yy];
		checked[xx][yy] = true;
		if (gxy == 0 && i ==3) { //0이면 상하좌우 이동 그만 ..
			printf("0만남 => (%d, %d) 상하좌우다보고,이동그만 hcnt:%d \n", xx, yy,hcnt);
			return;
		}
		else if (gxy == 0) {
			printf("0만남 => (%d, %d) 이동그만 \n", xx, yy);
		}
		else if (gxy == 1) {
			printf("1만남 => (%d, %d) %d 단지의: %d 번째 집\n",xx,yy,dcnt,hcnt+1);
			scnt = hcnt + 1;
			danji[dcnt] = hcnt + 1;
			find_danji_ofhome(xx,yy,dcnt, hcnt+1 );
			
		}
	}
}

int main() {

	int dcnt = 0;// 단지idx +1 해줄때 사용.
	//int hcnt = 0;// 1만날때 단지에 집 추가(+1)될때 사용 -> 단지+1 해줄때 0으로 초기화해주기.
	

	scanf_s("%d", &n);

	//1. 지도에 집 입력받기 (띄어쓰기 없이 정수형 입력)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &arr[i][j]);
			//printf("%d ", arr[i][j]);
		}
		//printf("\n");
	}

	//2. 2차원 배열에 저장된 수 중에서,
	//1이 끊기지 않고 이어지는 경우 하나의 단지로 취급해준다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checked[i][j] == false) { //탐색 시작
				checked[i][j] = true;
				
				if (arr[i][j] == 0) //0이면 checked하고 넘어감
					continue;
				else if (arr[i][j] == 1) {
					//hcnt = 0;
					dcnt += 1;
					printf("(%d,%d)시작! \n", i, j);
					find_danji_ofhome(i, j, dcnt, 1);
					//danji[dcnt] = homes;
					scnt = 0;
					printf("danji: %d = %d\n", dcnt, danji[dcnt]);
				}
			}
			else  continue;
		}
	}
	// 1이 있으면 1을 찾아 상하좌우를 뒤진다 . 모든 경우가 0만이 남게 되면 
	//거치기 않은 부분에서 가장 작은 [][]부터 다시 돌린다 ..? (확인하지 않은 곳)

	// 이미 지난 지점은 passed[][]배열에 true라저장하기 .
	//상하좌우를 확인할떄 passed가 true인 곳이면, 제외하고 , 칸보다 크면 제외하고,
	// 0이면 passed true하고 그곳에서 상하좌우 확인할 필요없음 
	//- 지금까지의 숫자를 단지배열에 저장

	//순서대로 출력하기 위해 sort시킴
	int size= sizeof(danji) / sizeof(danji[0]);
	sort(danji, danji+size);

	//5. 출력은 단지 배열을 sort시켜서 단지에 속하는 집의 수를 출력함
	for (int i = 0; i < size; i++) {
		if (danji[i] != 0) {
			printf("%d\n", danji[i]);
		}
	}

	return 0;
}
*/

//다시하기 ..
/*
#include <stdio.h>
#include <set>
using namespace std;
int N;
int map[27][27];
int home[27][27];
int danji = 0;
int cnt = 0;
//set <pair<int, int>> s;
set<int>s;
int main() {
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]); // 0 또는 1 입력받기
		}
	}
	
	for (int i = i; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) {
				home[i][j] = 0;
				continue;
			}
			else if (map[i][j] == 1) {
				if (i - 1 < 1 && j - 1 < 1) {
					//위와 앞 둘다 검사 필요없음
					danji++; //cnt = 1;
					home[i][j] = danji;
					//s.insert(danji, 1);
				}
				else if (i - 1 < 1) {//윗 검사 필요없음
					//앞이 0인 경우
					if (map[i][j - 1] == 0)
					{
						danji++; //cnt = 1;
						home[i][j] = danji;
						//s.insert(danji, 1); 
					}
					//앞이 1인 경우
					else {
						home[i][j] = danji; //현재 같은 단지 넣으면됨 
						//단지별로 개수 찾아오는방법 ....?
						if (s._Getpfirst == danji) {
							cnt = s.second
						}
						//s.insert(danji, cnt + 1);
					}
				}
				else if (j - 1 < 1) {//앞 검사 필요없음
					//위가 0인 경우
					if (map[i - 1][j] == 0) {
						danji++; //cnt=1;
						home[i][j] = danji;
						s.insert(danji, 1);
					}
					//위가 1인 경우
					else {

					}
				}
				else { //위와 앞 둘다 검사 필요 
					//앞위가 0인경우

					//앞위가 1인경우 (둘이 같은 단지인지 다른 단지인지 확인해야함)
					//home 의 값을 이용해서 비교하기 ..
					//앞이 0이고 위가 1인경우

					//앞이 1이고 위가 0인경우

				}
			}

		}
	}
	return 0;
}
*/