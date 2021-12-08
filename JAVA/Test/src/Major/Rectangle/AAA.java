package Major.Rectangle;

public class AAA {
    public static void main(String args[]){
        Rectangle r1 = new Rectangle(new Point(2,2), new Point(8,7));
        Rectangle r2 = new Rectangle(new Point(8,7), new Point(2,2));
        Rectangle r3 = new Rectangle(2,2,8,7);
        Rectangle r4 = new Rectangle(8,7,2,2);
        
        System.out.println(r1.area()); //! 넓이
        System.out.println(r2.getHeight()); //!높이
        System.out.println(r3.getWidth()); //!폭
        r4.printPoints();
    }
}