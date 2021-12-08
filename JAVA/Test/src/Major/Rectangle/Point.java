package Major.Rectangle;

public class Point {
    public int x,y; 
    public Point(int x, int y) { 
        this.x = x; this.y = y; 
    } 
    public boolean Xbtn(Point p1, Point p2) {
        return (x >= p1.x && x <= p2.x); 
    } 
    public boolean Ybtn(Point p1, Point p2) { 
        return (y >= p1.y && y <= p2.y); 
    } 
}