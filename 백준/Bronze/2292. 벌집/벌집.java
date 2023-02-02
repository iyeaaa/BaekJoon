import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n = Integer.parseInt(br.readLine());


		System.out.println(findSt(n));


	}


	


	static int findSt(int n) {


		int begin = 2, count = 1;


		


		if(n == 1)


			return 1;


		


		while( !( n >= begin && n <= begin+6*count-1 ) ) {


			begin += 6*count;


			count++;


		}


		


		return count+1;


	}


}


