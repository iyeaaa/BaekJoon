import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int x = Integer.valueOf(br.readLine());


		int y = Integer.valueOf(br.readLine());


		


		if( x > 0 ) {


			if( y > 0 )


				System.out.println("1");


			else


				System.out.println("4");


		}


		else {


			if( y > 0 )


				System.out.println("2");


			else


				System.out.println("3");


		}


	}


}