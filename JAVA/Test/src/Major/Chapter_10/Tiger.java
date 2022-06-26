package Major.Chapter_10;

public class Tiger extends Animal {
    public Tiger(int h, int d, String name)   {
        super(h,d,name);
    }
   @Override public void show() {
        System.out.println(name + " hp: " + hp);
   }
} 

