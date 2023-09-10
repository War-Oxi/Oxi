import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);


		//5\n
		Student[] students = new Student[5];

		for(int i = 0; i< 5; i++){
			int num = i+1;
			String name = sc.next();
			int score = sc.nextInt();

			students[i] = new Student(num, name, score);
		}

		System.out.println("번호\t이름\t점수\t등수" +
				"\n---------------------");
		for(int i=0; i<4; i++){
			for(int j=4; j>i; j--){
				if(students[j].getScore() < students[j-1].getScore())
					continue;

				Student tmp = students[j];
				students[j] = students[j-1];
				students[j-1] = tmp;
			}
			students[i].toString(i+1);
		}
		students[4].toString(5);
	}
}