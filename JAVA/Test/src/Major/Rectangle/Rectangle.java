package Major.Rectangle;

public class Rectangle {
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
        pt2 = new Point(x2,y2);
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
    }
    public void printPoints(){
        System.out.printf("(%d, %d), (%d, %d)", pt1.x, pt1.y, pt2.x, pt2.y);
    }
    public int area(){
        return getHeight()*getWidth();
    }

    public int getHeight(){
        return pt2.y-pt1.y;
    }

    public int getWidth(){
        return pt2.x-pt1.x;
    }
}
