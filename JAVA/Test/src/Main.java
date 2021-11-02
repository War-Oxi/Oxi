import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main{
    public static void main(String args[]){
        Scanner stdin = new Scanner(System.in);
<<<<<<< HEAD
        
        System.out.println("정수의 개수 입력: ");
        int i = stdin.nextInt(); 
        int score[] = new int[i];
        for (int j=0; j<i; j++)
        score[j] = stdin.nextInt();
        
        int min = score[0];
        int max = score[0];
        for (int j=0; j<score.length; j++){
            if(max<score[j])
                max=score[j];
=======
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
                if(j%mul==0)
                System.out.print(j+" ");
            }
>>>>>>> 7966e747793fcbddf459f7cb41e7ce193ad6a23d
        }
        for(int j=0; j<score.length; j++){
            if(min>score[j])
                min=score[j];
        }

        System.out.println(min+" "+max);
    }
}
<<<<<<< HEAD


/*
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 
둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
*/
=======
>>>>>>> 7966e747793fcbddf459f7cb41e7ce193ad6a23d
