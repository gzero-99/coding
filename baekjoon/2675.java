package bj200918;

import java.util.Scanner;

public class Bj2675 {//�������� Main���� �ٲٱ�.

	public static String repeatS(int R ,String S) {
		 
		//������
		String [] alpha = S.split("");
		for(int i=0; i<alpha.length;i++) {
			for(int j=1;j<=R;j++) {
				S = S.concat(alpha[i]);
			}
		}
		String str = S.substring(alpha.length);
		return str; //str
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		int  R;
		String S;
		T= sc.nextInt();	//�׽�Ʈ ���̽� ���� �Է� �ޱ� 
		String [] P = new String[T];
		
		for(int i=1;i<=T;i++) {
			R= sc.nextInt(); // �ݺ�Ƚ���Է� �ޱ�
			S= sc.next();
			P[i-1]= repeatS(R,S);
		}
		
		for(int j=1;j<=T;j++) {
			System.out.println(P[j-1]);
		}

	}
	
}

/*
package bj200918;

import java.util.Scanner;

public class Bj2675 {//�������� Main���� �ٲٱ�.

	public static String repeatS(int R ,String S) {
		 
		//������
		String [] alpha = S.split("");
		for(int i=0; i<alpha.length;i++) {
			for(int j=1;j<=R;j++) {
				S = S.concat(alpha[i]);
			}
		}
		return S;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		int [] R = null;
		String [] S = null;
		
		T= sc.nextInt();	//�׽�Ʈ ���̽� ���� �Է� �ޱ� 
		for(int i=1;i<=T;i++) {
			R[i-1]= sc.nextInt(); // �ݺ�Ƚ���Է� �ޱ�
			S[i-1]= sc.next();
		}
		
		for(int i=1;i<=T;i++) {
			int num=R[i-1];
			String str=S[i-1];
			System.out.println(repeatS(num,str));
		}
	}
	
}


*/