import java.util.Scanner;

public class Testfile2{
	public static void main(String[] args) {
        int sum1 = 0;
        int sum2 = 0;
        Scanner stdin = new Scanner(System.in);
        System.out.print("1~100사이의 임의의 수 : ");
        int a = stdin.nextInt();
        for(int i=a; i<=100; i+= a) //1번 1~100사이의 임의의 수의 배수의 합 구하기
            sum1 += i;
        for(int j=a; j<=100; j*=a ) //2번 1~100사이의 임의의 수의 거듭제곱의 합 구하기
            sum2 += j;
        System.out.println("1~100사이의 " + a +"의 배수의 합 : " + sum1);
        System.out.println("1~100사이의 " + a +"의 거듭제곱의 합 : " + sum2);
        
        stdin.close();
        int sum3=0, i=1;  //3번 문제
        while (i<100) {
            if (i%6 != 0) {
                i++;
                continue;
            }
            sum3 += i;
            i++;
        }
        System.out.println("1부터 100까지의 6의 배수의 합 : " + sum3);
        
        int sum4 =0; i=1;   //4번 문제
        for (i=6; i<100; i+=6) {
            sum4 += i;
        }
        System.out.println("1부터 100까지의 6의 배수의 합 : " + sum4);
	}
}