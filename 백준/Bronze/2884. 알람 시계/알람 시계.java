import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int h = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		if( h == 0 ) {
			if( m < 45 ) {
				h = 23;
				m += 15;
			}
			else
				m -= 45;
		}
		else {
			if( m < 45 ) {
				h -= 1;
				m += 15;
			}
			else
				m -= 45;
		}
		
		System.out.println(h + " " + m);
	}
}
