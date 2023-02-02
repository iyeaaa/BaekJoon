import java.io.*;



public class Main {


	public static void main(String [] args) throws IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


		int n1 = Integer.valueOf(br.readLine());


		String str = br.readLine();	


		int [] arr = new int [3];


		


		for(int i = 0; i < 3; i++) {


			arr[i] = n1*(str.charAt(2-i)-48);			


			System.out.println(arr[i]);


			arr[i] *= (int)Math.pow(10, i);


		}


		


		System.out.println(arr[0] + arr[1] + arr[2]);


	}


}