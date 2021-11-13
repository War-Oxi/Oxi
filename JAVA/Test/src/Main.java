import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main{
    public static void main(String args[]){
        Scanner Oxi = new Scanner(System.in);
        int array_list[] = new int[9];
        for(int i=0; i<array_list.length; i++){
            array_list[i] = Oxi.nextInt();
        }
        int max = array_list[0];
        int count = 1;
        for(int j: array_list){
            if(j>=max)
                max = j;
        }
        for(int j: array_list){
            if(j==max)
                break;
            count++;
        }
        System.out.println(max);
        System.out.println(count);
    }
}

/*
9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.

예를 들어, 서로 다른 9개의 자연수

3, 29, 38, 12, 57, 74, 40, 85, 61

이 주어지면, 이들 중 최댓값은 85이고, 이 값은 8번째 수이다.
*/

/*       
Scanner stdin = new Scanner(System.in);
List<Integer> list_num = new ArrayList<>();
System.out.print("정수들을 입력 > ");

int i=5;
while(true){
    i = stdin.nextInt();
    if (i<0)
        break;
    list_num.add(i);
}

System.out.print("검색할 배수 입력 > ");
int mul = stdin.nextInt();
iteration:{
    for(int j : list_num){
        if(j % mul ==0)
        System.out.print(j+" ");
    }
}
        */