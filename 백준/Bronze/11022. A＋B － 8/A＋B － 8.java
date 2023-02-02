import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n = Integer.parseInt(br.readLine());


		StringBuilder sb = new StringBuilder();


		


		for(int i = 0; i < n; i++) {


			String [] str = br.readLine().split(" ");


			int a = Integer.parseInt(str[0]);


			int b = Integer.parseInt(str[1]);


			sb.append("Case #" + (i+1) + ": " + a + " + " + b + " = ").append(a+b).append('\n');


		}


		System.out.println(sb);


	}


}