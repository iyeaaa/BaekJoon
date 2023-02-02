import java.util.Scanner;
public class Main{
	
    public static void main(String [] args){
        
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int count = 0, result = 0;
    	String [] problem = new String [n];
    	
    	for(int i = 0; i < n; i++)
    		problem[i] = sc.next();
    	
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < problem[i].length(); j++) {
    			if( problem[i].charAt(j)  == 79 ) {
    				count++;
    				result += count;
    			}
    			else 
    				count = 0;
    		}
    		System.out.println(result);
			result = 0; count = 0;
    	}
    	sc.close();
    }
}