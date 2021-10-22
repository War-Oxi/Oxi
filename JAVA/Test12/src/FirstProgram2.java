import java.util.Scanner;

public class FirstProgram2 {
	
	public static void main(String[] args) {
		int sum =0;
		for(int i = 10; sum <=100; i += 3){
			sum += i;
		}
		System.out.println(sum);

		int i=10;
		sum = 0;

		while (sum<100){
			sum += i;
			i += 3;
		}
		System.out.println(sum);
	}
}