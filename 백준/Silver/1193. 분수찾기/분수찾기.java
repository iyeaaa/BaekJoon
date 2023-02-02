import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		System.out.println(solution(Integer.parseInt(br.readLine())));


	}


	


	static String solution(int n) {


		int left = 1, right = 1;


		boolean even = true;


		


		for(int i = 1; i < n; i++) {


			if( even && left == 1 ) {


				right++; even = !even;


			}


			else if( !even && right == 1 )  {


				left++; even = !even;


			}


			else if( !even ) {


				left++; right--;


			}


			else {


				left--; right++;


			}


		}


		return left + "/" + right;


	}


}