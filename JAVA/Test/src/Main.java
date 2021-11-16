import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner stdin = new Scanner(System.in);

        int repeat_number = stdin.nextInt();

        for(int i=0; i<repeat_number; i++){
            Double score[] = new Double[stdin.nextInt()];
            Double sum = 0.0;
            Double count=0.0;

            for(int j=0; j<score.length; j++){
                score[j] = stdin.nextDouble();
                sum += score[j];
            }
            
            Double avg;
            avg = sum/score.length;

            for(int k=0; k<score.length; k++){
                if(score[k] > avg){
                    count++;
                }
            }
            System.out.printf("%.3f%%\n",(count/score.length)*100);
        }    
    }
}

/**
 ** "대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

 *! 첫째 줄에는 테스트 케이스의 개수 C가 주어진다. 
 
 *! 둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
*/
