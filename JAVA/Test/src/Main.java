/**
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
    N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
*/

import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner stdin = new Scanner(System.in);
        int num = stdin.nextInt();
        Main Han_Circulator = new Main();
        Han_Circulator.Han_Number(num);

    }

    void Han_Number(int a){
        int count=99;
        
        if(a<100){
            count = a;
        }
        else
        for(int i=100; i<=a; i++){
            int compare_num_a, compare_num_b;
            int b = i;
            int gap;
            while(true){
                compare_num_a = b % 10;
                b /= 10;
                compare_num_b = b % 10;
                if(b==0)
                    break;
                
                gap = compare_num_a-compare_num_b;
            }
            count++;
        }
        System.out.print(count);
    }
}