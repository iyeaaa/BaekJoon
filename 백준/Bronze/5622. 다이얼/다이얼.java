import java.io.*;


public class Main {
	
	public static void main(String [] args) throws IOException {
	
		StringBuilder [] sb = new StringBuilder [11];
		int sum = 0;
		
		sb[3] = new StringBuilder("ABC");	//3초
		sb[4] = new StringBuilder("DEF");
		sb[5] = new StringBuilder("GHI");
		sb[6] = new StringBuilder("JKL");
		sb[7] = new StringBuilder("MNO");
		sb[8] = new StringBuilder("PQRS");
		sb[9] = new StringBuilder("TUV");
		sb[10] = new StringBuilder("WXYZ");
		
		while(true) {
			char n = (char)System.in.read();
			if( n == '\n' )
				break;
			else {
				for(int i = 3; i < 11; i++)
					for(int j = 0; j < sb[i].length(); j++)
						if( n == sb[i].charAt(j) ) {
							sum += i;
						}
			}
		}
		System.out.println(sum);
	}
	
}