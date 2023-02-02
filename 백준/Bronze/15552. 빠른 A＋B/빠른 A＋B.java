import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n = Integer.parseInt(br.readLine());


		StringBuilder sb = new StringBuilder();


		


		while( n-- > 0 ) {


			String [] str = br.readLine().split(" ");


			int a = Integer.parseInt(str[0]);


			int b = Integer.parseInt(str[1]);


			sb.append(a+b).append('\n');


		}


		


		System.out.println(sb);


	}


}