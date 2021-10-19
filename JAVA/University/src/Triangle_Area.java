package chap02;
import java.util.Scanner;

public class Triangle_Area {
    public static void main(String[] args){
        
    	Scanner Triangle_info = new Scanner(System.in);
        
    	System.out.print("���� �ﰢ���� ���̸� �Է��Ͻÿ� : ");
        double height = Triangle_info.nextDouble();
        System.out.print("���� �ﰢ���� �ʺ� �Է��Ͻÿ� : ");        
        double width = Triangle_info.nextDouble();
        
        System.out.print("�� ���� �ﰢ���� ������ " + height*width/2 + " �Դϴ�.");
        Triangle_info.close();
        
    }
}
