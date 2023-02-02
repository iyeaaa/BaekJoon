import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		String [] str = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");


		final int A = Integer.parseInt(str[0]);


		final int B = Integer.parseInt(str[1]);


		final int C = Integer.parseInt(str[2]);


		


		System.out.println((A+B)%C);


		System.out.println(((A%C) + (B%C))%C);


		System.out.println((A*B)%C);


		System.out.println(((A%C) * (B%C))%C);


	}


}