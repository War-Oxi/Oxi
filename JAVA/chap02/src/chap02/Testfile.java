package chap02;


import java.util.Scanner;

public class Testfile{

	public static void main(String[] args) {
		Scanner Personal_Data = new Scanner(System.in);
		
		System.out.println("������ ������ �̸�, ����, Ű�� �����̽��ٷ� �����Ͽ� �Է��ϼ���.");
		
		String Nation = Personal_Data.next();
		String Name = Personal_Data.next();
		int Age = Personal_Data.nextInt();
		double Height = Personal_Data.nextDouble();

		System.out.println("���� ������ " + Nation + "�̸� �̸��� " + Name + "�Դϴ�");
		System.out.print("���̴� " + Age + "���̸� ");
		System.out.print("Ű�� " + Height + " �Դϴ�");
		Personal_Data.close();

	}
}
	