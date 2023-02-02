import java.io.*;


import java.util.*;



public class Main {


	


	public static void main(String [] args) throws IOException {


		


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		StringTokenizer st = new StringTokenizer(br.readLine());


		int [] arr = new int [2];


		


		for(int i = 0; i < 2; i++) {


			arr[i] = Integer.parseInt(st.nextToken());


			arr[i] = reverseNumber(arr[i]);


		}


		


		System.out.println(Math.max(arr[0], arr[1]));


		


	}


	


	static int reverseNumber(int number) {


		int result = 0;


		while( number != 0 ) {


			result = result*10 + number%10;


			number /= 10;


		}


		return result;


	}


	


}