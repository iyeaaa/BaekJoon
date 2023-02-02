import java.io.*;

public class Main {
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		sb.append(n*n*Math.PI + "\n" + (double)n*n*2);
		System.out.println(sb);
	}	// main
}	// class