import java.util.Scanner;

public class FirstProgram2 {
	static String o = "";
	public static void main(String[] args) {
		block1: for(int i=1;i<10;i++){
			System.out.print( i + " ");
			block2: for(int j=i; j< 10;j++){
				if(i*j>50)continue block1;
			}
			System.out.println();
		}
		System.out.println();
		block3:System.out.println("블럭3 수행");
	}
}