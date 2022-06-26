/**
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
*/
import java.util.Scanner;
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
