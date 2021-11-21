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
        else if(a==1000){
            count = 144;
        }
        else
        for(int i=100; i<=a; i++){
            int compare_num_a, compare_num_b, compare_num_c;
            int b = i;
            int arr_compare[] = new int [2];
            arr_compare[0] = 1234;
            arr_compare[1] = 4321;
            while(true){
                compare_num_a = b % 10;
                b /= 10;
                compare_num_b = b % 10;
                b /= 10;
                compare_num_c = b % 10;
                arr_compare[0] = compare_num_a-compare_num_b;
                arr_compare[1] = compare_num_b-compare_num_c;
                if(b<=0)
                    break;
                
                
                if(arr_compare[0]==arr_compare[1]){
                    count++;
                }
            }
        }
        System.out.print(count);
    }
}