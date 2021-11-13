import java.util.Scanner;

public class JavaReview5 {
    public static void main(String args[]){
        Scanner Input = new Scanner(System.in);
        System.out.print("1~99까지의 정수를 입력하세요 : ");
        int num = Input.nextInt();
        if(1<=num && num<=99){
            if((num%10%3 == 0) && (num/10%3 == 0)){
                System.out.println("박수짝짝");
            }
            else if ((num%10%3 == 0) ^ (num/10%3 == 0)){
                System.out.println("박수짝");
            }
        }
        else{
            System.out.println("잘못된 값 입력했다.");
        }
    }
}
