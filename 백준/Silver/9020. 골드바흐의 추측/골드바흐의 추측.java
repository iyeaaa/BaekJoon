import java.io.*;

public class Main {
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		while( t-- > 0 ) {
			int n = Integer.parseInt(br.readLine());
			int half = n/2;
			sb.append(halfPrime(half)).append("\n");
		}	// while
		
		System.out.println(sb);
	}	// main
	
	static String halfPrime(int half) {
		int i = 0, k = 0;
		
		for( i = half; i >= 2; i--) {
			k = 2*half - i;
			if( Notsosoo(i) || Notsosoo(k) )
				continue;
			break;
		}	// first for
		
		return i + " " + k;
	}	// findPrime
	
	static boolean Notsosoo(int n) {
		for(int j = 2; j*j <= n; j++)
			if( n % j == 0 ) 
				return true;
		return false;
	}
}	// class