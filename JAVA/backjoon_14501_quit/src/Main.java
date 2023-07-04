import java.util.Scanner;

public class Main {
    class Job{
        int period;
        int money;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Job[] jobList = new Job[N+1];

        for(int i=1; i<=N; i++){
            jobList[i].period = sc.nextInt();
            jobList[i].money = sc.nextInt();
        }

        int[] dp = new int[N+1];
        
    }
}