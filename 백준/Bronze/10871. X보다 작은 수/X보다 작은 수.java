import java.io.*;


import java.util.StringTokenizer;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		StringTokenizer st = new StringTokenizer(br.readLine());


		int n = Integer.parseInt(st.nextToken());


		int x = Integer.parseInt(st.nextToken());


		


		StringTokenizer st2 = new StringTokenizer(br.readLine());


		StringBuilder sb = new StringBuilder();


		


		while( n-- > 0 ) {


			int temp = Integer.parseInt(st2.nextToken());


			if( temp < x )


				sb.append(temp + " ");


		}


		


		System.out.println(sb);


	}


}