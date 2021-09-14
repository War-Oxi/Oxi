package chap02;


import java.util.Scanner;

public class Testfile{

	public static void main(String[] args) {
		Scanner Personal_Data = new Scanner(System.in);
		
		System.out.println("본인의 국적과 이름, 나이, 키를 스페이스바로 구분하여 입력하세요.");
		
		String Nation = Personal_Data.next();
		String Name = Personal_Data.next();
		int Age = Personal_Data.nextInt();
		double Height = Personal_Data.nextDouble();

		System.out.println("나의 국적은 " + Nation + "이며 이름은 " + Name + "입니다");
		System.out.print("나이는 " + Age + "살이며 ");
		System.out.print("키는 " + Height + " 입니다");
		Personal_Data.close();

	}
}
	