import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arrSize = 4;

		int[] num  = new int[arrSize+1];
		String[] name = new String[arrSize+1];
		int[] score = new int[arrSize+1];

		for(int i=1; i<=arrSize; i++){
			num[i-1] = i;
			System.out.print(i + "번 이름 : ");
			name[i-1] = sc.next();
			System.out.print(i + "번 점수 : " );
			score[i-1] = sc.nextInt();
			System.out.println();
		}

		System.out.println("번호 이름 점수 등수\n" +
				"----------------------");
		for(int i=0; i<arrSize-1; i++){
			for(int j=arrSize-1; j>=i; j--){
				if(score[j] < score[j+1]){
					num[arrSize] = num[j];
					score[arrSize] = score[j];
					name[arrSize] = name[j];

					num[j] = num[j+1];
					score[j] = score[j+1];
					name[j] = name[j+1];

					num[j+1] = num[arrSize];
					score[j+1] = score[arrSize];
					name[j+1] = name[arrSize];
				}
			}
			System.out.printf("%d  %s  %d  %d\n", num[i], name[i], score[i], i+1);
		}
		System.out.printf("%d  %s  %d  %d", num[arrSize-1], name[arrSize-1], score[arrSize-1], arrSize);
	}
}