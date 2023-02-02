import java.util.Scanner;

public class Main {
	
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 99;
		
		for(int i = 100; i <= n; i++) 
			if(minusTest(i))
				count++;
		
		System.out.println( n < 100 ? n : count);
		
		sc.close();
	}
	
	static boolean minusTest(int n) {
		return n == 1000 ? false : n%10 - (n/10)%10 == (n/10)%10 - (n/100)%10;
	}
	
}