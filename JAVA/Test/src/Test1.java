//!1~100사이에서 임이의 수의 배수의 합을 구하는 프로그램
import java.util.Scanner;

public class Test1{
    public static void main(String args[]){
        Scanner stdin = new Scanner(System.in);
        System.out.print("정수의 개수 입력: ");
        int i = stdin.nextInt();
        int score[] = new int[i];
        int min = 1000000;
        int max = -1000000;

        for (int j=0; j<i; j++){
            score[j] = stdin.nextInt();
            if(max<score[j])
                max=score[j];
            if(min>score[j])
                min=score[j];
        }
        
        System.out.println(min+" "+max);
        stdin.close();
    }
}
