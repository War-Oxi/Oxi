package Major.Rectangle;

public class Rectangle {
<<<<<<< Updated upstream
    private Point pt1, pt2;
    public Rectangle(Point p1, Point p2) {
       if (p1.x < p2.x) {
           pt1 = p1;
           pt2 = p2;
       } else {
          pt1 = p2;
          pt2 = p1;
       }
=======
    private Point pt1;
    private Point pt2;
    public Rectangle(Point p1, Point p2){
        int changer;
        pt1 = p1;
        pt2 = p2;
        if(pt1.x > pt2.x){
            changer = pt1.x;  
            pt1.x = pt2.x;
            pt2.x = changer;
        }
        if(pt1.y > pt2.y){
            changer = pt1.y;
            pt1.y = pt2.y;
            pt2.y = changer;
        }
    }
    public Rectangle(int x1,int y1,int x2,int y2){
        int changer;
        pt1 = new Point(x1,y1);
        pt2 = new Point(x2,y2 );
        if(x1>x2){
            changer = pt1.x;
            pt1.x = pt2.x;
            pt2.x = changer;
        }
        if(y1>y2){
            changer = pt1.y;
            pt1.y = pt2.y;
            pt2.y = changer;
        }
>>>>>>> Stashed changes
    }

    public Rectangle(int x1, int y1, int x2, int y2) {
       this(new Point(x1, y1), new Point(x2, y2) );
    }   
    public int getHeight() {
        return pt2.y - pt1.y;
    }
    public int getWidth() {
        return pt2.x - pt1.x;
    }
    public void printPoints() {
        System.out.printf("(%d, %d), (%d, %d)\n" , pt1.x , pt1.y, pt2.x, pt2.y);
    }
    public Rectangle getIntersection(Rectangle r2) {
        Rectangle r1 = this;
        int x1, y1, x2, y2;
        if ( r1.pt1.Xbtn(r2.pt1, r2.pt2) && r1.pt1.Ybtn(r2.pt1, r2.pt2)) {
            if ( r1.pt2.Xbtn(r2.pt1, r2.pt2) && r1.pt2.Ybtn(r2.pt1, r2.pt2)) { 
                x1 = r1.pt1.x; y1=r1.pt1.y; x2=r1.pt2.x; y2=r1.pt2.y;
            }
            else {
                x1 = r2.pt1.x; y1=r2.pt1.y; x2=r1.pt2.x; y2=r1.pt2.y;
            }   
        }
        else if (r2.pt1.Xbtn(r1.pt1, r1.pt2) && r2.pt1.Ybtn(r1.pt1, r1.pt2)) {
            if ( r2.pt2.Xbtn(r1.pt1, r1.pt2) && r2.pt2.Ybtn(r1.pt1, r1.pt2)) { 
                x1 = r2.pt1.x; y1=r2.pt1.y; x2=r2.pt2.x; y2=r2.pt2.y;
            }
            else {
                x1 = r2.pt1.x; y1=r2.pt1.y; x2=r1.pt2.x; y2=r1.pt2.y;
            } 
        }
        else if (r2.pt1.Xbtn(r1.pt1, r1.pt2) && r2.pt2.Ybtn(r1.pt1, r1.pt2)) {
            x1 = r2.pt1.x; y1=r1.pt1.y; x2=r1.pt2.x; y2=r2.pt2.y;
        }
        else if (r1.pt1.Xbtn(r2.pt1, r2.pt2) && r1.pt2.Ybtn(r2.pt1, r2.pt2)) {
            x1 = r1.pt1.x; y1=r2.pt1.y; x2=r2.pt2.x; y2=r1.pt2.y;
        }
        else 
            return null;
        return new Rectangle(new Point(x1, y1), new Point(x2, y2));
    }          
    
    public static Rectangle getIntersection(Rectangle r1, Rectangle r2) {
        
        return r1.getIntersection(r2);
    }
    //         inter = Rectangle.getIntersection(r1, r2);   이 되도록 메소드를 구현하시오.
}
