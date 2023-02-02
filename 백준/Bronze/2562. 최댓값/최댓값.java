import java.io.*;
import java.util.*;

public class Main {
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int count = 1;
		
		for(int i = 2; i <= 9; i++) {
			int temp = Integer.parseInt(br.readLine());
			if( n < temp ) {
				n = temp;
				count = i;
			}
		}	// for
		
		System.out.println(n + "\n" + count);
	}	// main method
}	// Main class