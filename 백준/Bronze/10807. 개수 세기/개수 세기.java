import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[] num = new int[n];
		for(int i=0; i<n; i++) {
			num[i] = sc.nextInt();
		}
		int findNum = sc.nextInt();
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(num[i] == findNum) {
				cnt++;
			}
		}
		System.out.println(cnt);
		sc.close();
	}
} 