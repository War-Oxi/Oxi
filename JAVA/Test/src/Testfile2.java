import java.util.Scanner;

public class Testfile2 {
    public static void main(String[] args){
        
    	Scanner Minus_Program = new Scanner(System.in);
        
    	int Num1 = Minus_Program.nextInt();
        int Num2 = Minus_Program.nextInt();
        System.out.println(Num1 + "-" + Num2 + "의 결과는 " +(Num1-Num2) + "입니다");
    }
}