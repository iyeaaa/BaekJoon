import java.io.*;



public class Main {


	


	public static void main(String [] args) throws IOException {


		


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		


		int sum = Integer.parseInt(br.readLine());


		sum *= Integer.parseInt(br.readLine());


		sum *= Integer.parseInt(br.readLine());


		


		String s = String.valueOf(sum);


		


		int [] arr = new int [10];


		


		for(int i = 0; i < s.length(); i++) 


			arr[s.charAt(i)-48]++;


		


		for(int i = 0; i < 10; i++)


			System.out.println(arr[i]);


		


	}


	


}