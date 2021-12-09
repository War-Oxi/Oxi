//!1~100사이에서 임이의 수의 배수의 합을 구하는 프로그램
import java.util.Scanner;

class Ct{
    public Ct(){
        System.out.println("매개 변수 없음");
    }
    public Ct(int a){
        System.out.println("매개 변수 int a");
    }
    public Ct(double a){
        System.out.println("매개 변수 double a");
    }
    public Ct(int a, double b){
        System.out.println("매개 변수 int a, double b");
    }
}

public class Test1{
    public static void main(String args[]){
        Ct cto = new Ct(3, 7);
        cto = new Ct(4);
        cto = new Ct(4, 4.15);
        cto = new Ct(6.0);
        cto = new Ct(3,7);
    }
}
