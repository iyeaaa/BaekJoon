import java.util.Scanner;
public class Main{
	
    public static void main(String [] args){
        
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	double [] score = new double [n];
    	double average = 0;
    	
    	for(int i = 0; i < n; i++)
    		score[i] = sc.nextDouble();
    	
    	double max = score[0];
    	
    	for(int i = 0; i < n; i++) 
    		if(max < score[i])
    			max = score[i];
    	
    	for(int i = 0; i <n; i++) {
    		score[i] = score[i] * 100 / max;
    		average += score[i];
    	}
    	
    	System.out.print(average/n);
    	sc.close();
    	
    }
}