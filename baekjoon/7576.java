//장지영 [백준] 토마토 java ,,메모리랑 시간 효율을 위해서는 자바 지양하자..
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main{

	private static int[] row = {-1,0,1,0};
	private static int[] col = {0,1,0,-1};

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M,N;
		M = sc.nextInt();
		N = sc.nextInt();
		int [][] box = new int [N][M];
		int [][] count = new int[N][M];
		boolean [][]checked = new boolean [N][M];
		int cnt ;
		//bfs 작업을 위한 queue 선언
		Queue<Node>queue =new LinkedList<Node>();


		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				box[i][j]=sc.nextInt();
				if(box[i][j] == 1) { //1인 애들 큐에 연결.. 시작점임!
					checked[i][j]=true;
					queue.add(new Node(i,j));
				}
				
			}
		}

		
		//BFS();		
		//queue가 빌때까지 box의 좌표를 방문하며 탐색 
				while(!queue.isEmpty()) {
					//탐색 후보노드 정보가 queue에 dlTdma
					//하나씩 poll해서 탐색. - 첫번째 값을 반환하고 제거.
					Node node=queue.poll();
					//poll해 얻을 node 객체에서 row,col 정보 가져오기
					int r = node.x;
					int c = node.y;
					
					//4개 방향 탐색 
					for(int i=0;i<4;i++) {
						int rr = r + row[i];
						int cc = c + col[i];
						//box배열 사이즈에 들어가는 지 확인
						if(rr<0||rr>=N||cc<0||cc>=M)continue;
						//이미 방문한 좌표면 굳이 후보노드 아니어도되어 필터링해줌
						
						if(	box[rr][cc]==0 && checked[rr][cc]==false)	//익지 않은 토마토면,, 
						{
							checked[rr][cc]=true;
							box[rr][cc]=1;//이제 익게된다.
							//익은 토마토면, 큐에 추가해준다.
							queue.add(new Node(rr,cc));
							count[rr][cc] = count[r][c]+1;
						}
					}
					
				}
		/*		
		//출력 연습
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(checked[i][j]+" ");
			}
			System.out.println();
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(count[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
		 */
		cnt = 0;
		Loop1 :
		for(int i=0;i<N;i++) {
			Loop2 :
			for(int j=0;j<M;j++) {
				//다 돌렸음에도 , 0을 가진 애가 있고, 지나간 적이 없는 애면 ! cnt =-1
				if(box[i][j]==0 && checked[i][j]==false) {
					cnt=-1;
					break Loop1;
				}
				else if(count[i][j]>cnt) {
					cnt = count[i][j];
					
				}
			}	
		}
		
		if(cnt == -1)
			System.out.println("-1");
		else
			System.out.println(cnt);


	}

}
//노드 정보 저장할 class
class Node{
	int x;
	int y;
	public Node(int x,int y) {
		this.x = x;
		this.y = y;
	}
}
