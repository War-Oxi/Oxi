package Major.Chapter_9;

class Inner{
    private int x;
    public void setX(int x){
        this.x = x;
    }
    public int getX(){
        return x;
    }
}
class Outer{
    private Inner y;
    public void setY(Inner y){
        this.y = y;
    }
    public Inner getY(){
        return y;
    }
}
class Main{
    public static void main(String args[]){
        Inner i = new Inner();
        Outer o = new Outer();
        int n = 10;
        i.setX(n);
        o.setY(i);

        System.out.println(o.getY().getX());
    }
}
