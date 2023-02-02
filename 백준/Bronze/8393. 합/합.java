import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n = Integer.parseInt(br.readLine());


		int answer = 0;


		


		while( n-- > 0 ) {


			answer += n+1;


		}


		


		System.out.println(answer);


	}


}