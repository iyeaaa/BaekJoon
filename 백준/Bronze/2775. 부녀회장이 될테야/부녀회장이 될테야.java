import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int times = Integer.parseInt(br.readLine());


		StringBuilder sb = new StringBuilder();


		


		while( times-- > 0 ) {


			int k = Integer.parseInt(br.readLine());


			int n = Integer.parseInt(br.readLine());


			sb.append(solution(k, n) + '\n');


		}


		


		System.out.println(sb);


	}



	private static String solution(int k, int n) {


		int answer = 0;


		int [][] apart = new int [k+1][n];


	


		for(int i = 0; i <= k; i++) {


			for(int j = 0; j < n; j++) {


				if( i == 0 )


					apart[i][j] = j+1;


				else if( j == 0 )


					apart[i][j] = 1;


				else


					apart[i][j] = apart[i-1][j] + apart[i][j-1];


			}


		}


		


		answer = apart[k][n-1];


		return String.valueOf(answer);


	}


}