import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String [] args) throws IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int [] arr = new int [3]; 
		
		for(int i = 0; i < 3; i++)
			arr[i] = Integer.parseInt(st.nextToken());
			
		if( arr[1] >= arr[2] ) {
			System.out.println(-1);
			return;
		}
		
		int profit = arr[2] - arr[1];
		
		System.out.println( arr[0]/profit+1 );
		
	}
	
}