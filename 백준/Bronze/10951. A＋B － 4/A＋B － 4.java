import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		String input = "";


		


		while( (input = br.readLine()) != null ) {


			String [] str = input.split(" ");


			int a = Integer.parseInt(str[0]);


			int b = Integer.parseInt(str[1]);


			


			System.out.println(a+b); 


		}


	}


}