import java.io.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] str = br.readLine().split(" ");
		
		int x = Integer.parseInt(str[0]);
		int y = Integer.parseInt(str[1]);
		int w = Integer.parseInt(str[2]);
		int h = Integer.parseInt(str[3]);
		
		int min = min( min(x, w-x), min(y, h-y));
		
		System.out.println(min);
	}	// main
}	// class