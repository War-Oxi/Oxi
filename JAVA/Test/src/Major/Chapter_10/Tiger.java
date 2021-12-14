package Major.Chapter_10;

public class Tiger extends Animal {
    public String name;
    public Tiger(int h, int d, String name)   {
        super(h,d);
        this.name = name;
    }
   @Override public void show() {
        System.out.println(name + " hp: " + hp);
   }
} 

