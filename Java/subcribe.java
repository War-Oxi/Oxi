import java.util.Scanner;

public class subcribe{
    public static void main(String[] args){
        Scanner stdln = new Scanner(System.in);
        System.out.print("Name, Age, Weight : ");
        String name = stdln.next();
        int i = stdln.nextInt();
        double d = stdln.nextDouble();
        System.out.println(name + "씨의 나이는 " + i + "세이고");
        System.out.println("몸무게는 " + d + " Kg 입니다.");
    }
}