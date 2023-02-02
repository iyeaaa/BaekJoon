import java.io.*;
import static java.lang.Math.*;

public class Main {
	
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		System.out.println(fibonacci(n));
	}	// main
	
	static int fibonacci(int n) {
		return n <= 1 ? n : fibonacci(n-1) + fibonacci(n-2);
	}	// fibonacci
}	// class 