import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		String [] str = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");


		int [] arr = new int [3];


		


		for(int i = 0; i < 3; i++)


			arr[i] = Integer.parseInt(str[i]);


		


		double max = arr[2] - arr[0];


		System.out.println( (int)Math.ceil(max/(arr[0]-arr[1])) + 1 );


	}


}