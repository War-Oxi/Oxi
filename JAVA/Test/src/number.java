import java.util.Scanner;

//!두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
//!입력 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
//!출력 각 테스트 케이스마다 A+B를 출력한다.

/*예제 입력 1 
5
1 1
2 3
3 4
9 8
5 2*/

/*예제 출력 1 
2
5
7
17
7*/

public class number{
    public static void main(String args[]){
        Scanner stdln = new Scanner(System.in);
        System.out.println("입력 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)");
        int num = stdln.nextInt();
        int A;
        int B;
        for(int i=1;i<=num;i++){
            System.out.println("A의 값 : ");
            A = stdln.nextInt();
            System.out.println("B의 값 : ");
            B = stdln.nextInt();
            if(A>0 && B<10){
            System.out.println(A+B);
            }
            else{
                System.out.println("잘못된 값");
            }
        }
        System.out.println("모든 테스트가 끝이 났습니다.");
        stdln.close();
    }
}