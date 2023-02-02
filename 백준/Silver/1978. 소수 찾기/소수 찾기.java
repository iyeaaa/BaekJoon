import java.io.*;
import java.util.*;

public class Main {
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int count = 0;
		
		while( n-- > 0 ) {
			int temp = Integer.parseInt(st.nextToken());
			boolean sosu = true;
			
			if( temp == 1 )
				sosu = false;
			
			for(int i = 2; i < temp; i++)
				if( temp % i == 0 ) {
					sosu = false;
					break;
				}
			
			if( sosu ) 
				count++;
		}
		
		System.out.println(count);
	}
}