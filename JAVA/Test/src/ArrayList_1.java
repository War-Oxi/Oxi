import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class ArrayList_1{
    public static void main(String args[]){
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

        stdin.close();
    }
}