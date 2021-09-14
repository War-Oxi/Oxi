package chap02;
import java.util.Scanner;

public class Triangle_Area {
    public static void main(String[] args){
        
    	Scanner Triangle_info = new Scanner(System.in);
        
    	System.out.print("직각 삼각형의 높이를 입력하시오 : ");
        double height = Triangle_info.nextDouble();
        System.out.print("직각 삼각형의 너비를 입력하시오 : ");        
        double width = Triangle_info.nextDouble();
        
        System.out.print("이 직각 삼각형의 면적은 " + height*width/2 + " 입니다.");
        Triangle_info.close();
        
    }
}
