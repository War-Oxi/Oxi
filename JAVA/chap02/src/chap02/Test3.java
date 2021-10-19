//!1부터 100까지 3의 배수를 더하는 while문이다 빈칸에 적절한 코드를 삽입하라
package chap02;

import java.util.Scanner;

public class Test3 {
    public static void main(String args[]){
        int sum=0, i=1;
        while(i<100){
            if(i%6 != 0){
                i++;
                continue;
            }
            sum += i;
            i++;
        }
        System.out.println(sum);
    }
}
