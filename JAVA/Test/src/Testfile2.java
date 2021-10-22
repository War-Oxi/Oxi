import java.lang.annotation.Native;
import java.util.Scanner;

public class Testfile2 {
    public static void main(String[] args){
        Scanner Money = new Scanner(System.in);
        System.out.println("금액을 입력하세요 : ");
        int money = Money.nextInt();
        System.out.println("일만원권 : " + money / 10000);
        System.out.println("천원권 : " + money % 10000 / 1000);
        System.out.println("오백원주화 : " + money % 1000 / 500);
        System.out.println("백원주화 : " + money % 500 / 100);
        System.out.println("십원주화 : " + money % 100 / 10);
        System.out.println("일원주화 : " + money % 10 / 1);
        System.out.println("끝났습니다");
    }
}