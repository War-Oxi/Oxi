package Major.Rectangle;
import java.util.Scanner;

public class JavaApp1 { /** * @param args the command line arguments */ 
  public static void main(String[] args) {
    //! code application logic here //Point p1, p2;
    Scanner StdIn = new Scanner(System.in); 
    Rectangle r1,r2; 
    r1 = new Rectangle( new Point(2,5), new Point (9,12));
    r2 = new Rectangle( new Point(4,3), new Point (10,7)); 
    Rectangle inter = r1.getIntersection(r2);
    r1.printPoints(); 
    r2.printPoints(); 
    if (inter != null) 
      inter.printPoints();
    else
      System.out.println("교접하는 사각형이 없습니다.");
    r1 = new Rectangle( new Point(2,2), new Point (9,12));
    r2 = new Rectangle( new Point(4,3), new Point (5,7));
    
    inter = Rectangle.getIntersection(r1, r2);
    r1.printPoints();
    r2.printPoints(); 
    if (inter != null) 
      inter.printPoints();
    else
      System.out.println("교접하는 사각형이 없습니다.");
  }
}