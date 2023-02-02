import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		String [] str = br.readLine().split(" ");


		


		int a = Integer.parseInt(str[0]);


		int b = Integer.parseInt(str[1]);


		int c = Integer.parseInt(str[2]);


		


		if( a == b && b == c )


			System.out.println( 10000 + a*1000 );


		else if ( a ==  b || a == c )


			System.out.println( 1000 + a*100 );


		else if ( b == c )


			System.out.println( 1000 + b*100 );


		else 


			System.out.println(100*Math.max(Math.max(a, b), c));	


	}


}