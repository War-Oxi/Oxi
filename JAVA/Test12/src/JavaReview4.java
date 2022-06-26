/*1번 답
 *  
	sum = ((sum>100) ? (sum=200) : (sum=0));
 */

import java.util.Scanner;

public class JavaReview4 {
    public static void main(String args[]){
        Scanner Input = new Scanner(System.in);
        System.out.print("2자리수 정수 입력(10~99) : ");
        int num1 = Input.nextInt();
        if(10<=num1 && num1 <= 99){
            if(num1/10==num1%10){
                System.out.println("Yes! 10의 자리와 1의 자리가 같습니다.");
            }
            else{
                System.out.println("No! 10의 자리와 1의 자리가 다릅니다.");
            }
        }
        else{
            System.out.println("잘못된 범위의 값인 num1을 입력하셨습니다.");
        }
        Input.close();
    }
}