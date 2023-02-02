import java.io.*;
import static java.lang.Math.*;

public class Main {
	
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		
		while( t-- > 0 ) {
			String [] str = br.readLine().split(" ");
			int x1 = Integer.parseInt(str[0]);
			int y1 = Integer.parseInt(str[1]);
			int r1 = Integer.parseInt(str[2]);
			int x2 = Integer.parseInt(str[3]);
			int y2 = Integer.parseInt(str[4]);
			int r2 = Integer.parseInt(str[5]);
			double dist = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
			if ( r1 > r2 ) 
				solution( r2, r1, dist );
			else
				solution( r1, r2, dist );
		}
		System.out.println(sb);
	}	// main
	
	static void solution(int r1, int r2, double dist) {
		if( dist == 0 ) {
			if( r1 == r2 ) {
				if( r1 == 0 )
					sb.append(1);
				else
					sb.append(-1);
			}
			else {
				sb.append(0);
			}
		}
		else {
			if( r1 + r2 < dist )
				sb.append(0);
			else if( r1 + r2 == dist )
				sb.append(1);
			else {	// r1 + r2 > dist
				if( dist + r1 > r2)
					sb.append(2);
				else if( dist + r1 == r2)
					sb.append(1);
				else if (dist + r1 < r2)
					sb.append(0);
			}
		}
		sb.append("\n");
	}	//solution
}	// class