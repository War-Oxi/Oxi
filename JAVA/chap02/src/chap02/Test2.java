package chap02;
import java.util.Scanner;

public class Test2 {
    public static void main(String args[]){
        Scanner Mul_Plus = new Scanner(System.in);
        int num = Mul_Plus.nextInt();
        int result = 0;
        for (int i=num; i<=100; i*=num){
            result += i;
        }
        System.out.println(result);
    }
}
