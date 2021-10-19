package chap02;
import java.util.Scanner;

public class KeyboardInput2 {
    public static void main(String[] args){
        Scanner stdIn = new Scanner(System.in);
        System.out.print("�̸��� ����, ������ ����(space)���� �����Ͽ� �Է� : ");
        String name = stdIn.next();
        int i = stdIn.nextInt();
        double d = stdIn.nextDouble();
        System.out.println(name + "���� ���̴� " + i + "���̰�");
        System.out.println("�����Դ� " + d + "Kg �Դϴ�.");

        stdIn.close();
    }
}
