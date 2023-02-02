import java.io.*;


import java.util.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n = Integer.valueOf(br.readLine());


		StringTokenizer [] st = new StringTokenizer[n];


		int [][] arr = new int [n][3];


		


		for(int i = 0; i < n; i++) {


			st[i] = new StringTokenizer(br.readLine());


			for(int j=0; j < 3; j++)


				arr[i][j] = Integer.parseInt(st[i].nextToken());


		}


	


		for(int i = 0; i < n; i++)


			System.out.println(solution(arr[i][0], arr[i][1], arr[i][2]));


	}


	


	static String solution(int h, int w, int n) {


		


		int first = 0, last = 0;


		


		if( n % h == 0 ) {


			first = h;


			last = n/h;


		}


		else {


			first = n%h;


			last = n/h+1;


		}


		String reallast = String.valueOf(last);


		


		if( last < 10 )


			reallast = "0" +  last;


		


		return first + "" + reallast;


	}


}