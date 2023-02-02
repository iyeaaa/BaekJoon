import java.io.*;


import java.math.BigInteger;



public class Main {


	public static void main(String [] args) throws IOException {


		String [] str = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");


		BigInteger n1 = new BigInteger(str[0]);


		BigInteger n2 = new BigInteger(str[1]);


		System.out.println(n1.add(n2));


	}


}