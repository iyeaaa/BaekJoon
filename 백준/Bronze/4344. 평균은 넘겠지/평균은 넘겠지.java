import java.util.Scanner;
public class Main{
	static int n, num = 0;
    public static void main(String [] args){
    	Scanner sc = new Scanner(System.in);
    	n = sc.nextInt();
    	int [] people = new int [n];
    	double [] ratio = new double [n];
    	for(int i = 0;  i < n; i++) {
    		people[i]  = sc.nextInt();
    		int [] score = new int [people[i]];
    		for(int j = 0; j < people[i]; j++)
    			score[j] = sc.nextInt();
    		OVerAverage(score, ratio);
    	}
    	
    	for(int i = 0; i < n; i++)
    		System.out.printf("%.3f%%%n",ratio[i]);
    	sc.close();
    }

	private static void OVerAverage(int [] score, double [] ratio) {
		double average = 0, count = 0;
		
		for(int i = 0; i < score.length; i++) 
			average += score[i];
		average /= score.length;
		
		for(int i =0; i < score.length; i++) {
			if( score[i] > average)
				count += (double)100 / score.length;
		}
		
		ratio[num] = count;
		num++;
		
	}
}