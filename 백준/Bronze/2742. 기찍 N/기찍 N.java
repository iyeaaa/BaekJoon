import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n = Integer.parseInt(br.readLine());


		StringBuilder sb = new StringBuilder();


		


		while(n-- > 0)


			sb.append(n+1).append('\n');


		


		System.out.println(sb);


	}


}