import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		StringBuilder sb = new StringBuilder();


		


		while(true) {


			String [] str = br.readLine().split(" ");


			int a = Integer.parseInt(str[0]);


			int b = Integer.parseInt(str[1]);


			


			if( a == 0 && b == 0 )


				break;


			


			sb.append(a+b).append('\n');


		}


		System.out.println(sb);


	}


}


