//!1~100사이에서 임이의 수의 배수의 합을 구하는 프로그램
package chap02;
import java.util.Scanner;

public class Test1 {
    public static void main(String args[]){
        Scanner Plus = new Scanner(System.in);
        int Num = Plus.nextInt();
        int Result = 0;
        for (int i = Num; i<=100; i+=Num){
            Result += i;
        }
        System.out.println(Result);
    }
}
