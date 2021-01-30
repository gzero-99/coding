//������ [����] �丶�� java ,,�޸𸮶� �ð� ȿ���� ���ؼ��� �ڹ� ��������..
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
		//bfs �۾��� ���� queue ����
		Queue<Node>queue =new LinkedList<Node>();


		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				box[i][j]=sc.nextInt();
				if(box[i][j] == 1) { //1�� �ֵ� ť�� ����.. ��������!
					checked[i][j]=true;
					queue.add(new Node(i,j));
				}
				
			}
		}

		
		//BFS();		
		//queue�� �������� box�� ��ǥ�� �湮�ϸ� Ž�� 
				while(!queue.isEmpty()) {
					//Ž�� �ĺ���� ������ queue�� dlTdma
					//�ϳ��� poll�ؼ� Ž��. - ù��° ���� ��ȯ�ϰ� ����.
					Node node=queue.poll();
					//poll�� ���� node ��ü���� row,col ���� ��������
					int r = node.x;
					int c = node.y;
					
					//4�� ���� Ž�� 
					for(int i=0;i<4;i++) {
						int rr = r + row[i];
						int cc = c + col[i];
						//box�迭 ����� ���� �� Ȯ��
						if(rr<0||rr>=N||cc<0||cc>=M)continue;
						//�̹� �湮�� ��ǥ�� ���� �ĺ���� �ƴϾ�Ǿ� ���͸�����
						
						if(	box[rr][cc]==0 && checked[rr][cc]==false)	//���� ���� �丶���,, 
						{
							checked[rr][cc]=true;
							box[rr][cc]=1;//���� �ͰԵȴ�.
							//���� �丶���, ť�� �߰����ش�.
							queue.add(new Node(rr,cc));
							count[rr][cc] = count[r][c]+1;
						}
					}
					
				}
		/*		
		//��� ����
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
				//�� ���������� , 0�� ���� �ְ� �ְ�, ������ ���� ���� �ָ� ! cnt =-1
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
//��� ���� ������ class
class Node{
	int x;
	int y;
	public Node(int x,int y) {
		this.x = x;
		this.y = y;
	}
}
