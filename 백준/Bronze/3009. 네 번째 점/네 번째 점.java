import java.io.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] str;
		int [][] arr = new int [3][2];
		
		for(int i = 0; i < 3; i++) {
			str = br.readLine().split(" ");
			arr[i][0] = Integer.parseInt(str[0]);
			arr[i][1] = Integer.parseInt(str[1]);
		}
		
		System.out.println(findNum(arr,0) + " " + findNum(arr,1));
	}	// main
	
	static int findNum(int [][] arr, int i) {
		if( arr[0][i] == arr[1][i] )
			return arr[2][i];
		else if ( arr[0][i] == arr[2][i] )
			return arr[1][i];
		else
			return arr[0][i];
	}
}	// class