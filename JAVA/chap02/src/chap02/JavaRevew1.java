package chap02;
import java.util.Scanner;

public class JavaRevew1 {
    public static void main(String args[]){
    	Scanner Num = new Scanner(System.in);
        System.out.println("1~100까지 임의의 수 입력");
        int num = Num.nextInt();
        int sum = 0;

        for(int i=num; i<=100; i+=num){
            sum += i;
        }
        System.out.println("1~100사이의 " + num + "의 배수의 합은 = "+ sum);
        sum = 0;
        for(int i=num; i<=100; i*=num){
            sum += i;
        }
        System.out.println("1~100사이의 " + num + "의 거듭제곱의 합은 = " + sum);

        int sum1=0, i=1;
        while(i<100){
            if (i%6 != 0){
                i++;
                continue;
            }
            sum1 += i;
            i++;
        }
        System.out.println("1부터 100까지 6의 배수의 합은? " + sum1);

        int sum2 =0; i=1;
        for(i=6; i<100; i+=6){
            sum2 += i;
        }
        System.out.println("1부터 100까지 6의 배수의 합은? " + sum1);
    }
}