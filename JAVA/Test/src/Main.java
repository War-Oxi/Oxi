import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main{
    public static void main(String args[]){
        String list[] = {"seoul","daejeon","daegu","kwangju","inchon","jeju","busan"};
        System.out.println("원래의 배열");
        for (String S : list)
            System.out.print(S+", ");
        System.out.println();
        for(int i=0; i<list.length / 2; i++){
            String temp = list[i];
            list[i] = list[list.length - i -1];
            list[list.length -i -1] = temp;
        }
        System.out.println("역순으로 배열한 후");
        for (String S : list)
            System.out.print(S+", ");
    }
}


/*
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 
둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
*/
