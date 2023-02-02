import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int originalN = Integer.parseInt(br.readLine());


		int count = 0,  ten = 0, one = 0, copyN = originalN;


		while( true ) {


			ten = (copyN%10)*10;	// after의 ten


			one = (copyN/10 + copyN%10)%10;	// after의 one


			copyN = ten + one;


			count++;


			if( copyN == originalN)


				break;


		}


		System.out.println(count);


	}


}