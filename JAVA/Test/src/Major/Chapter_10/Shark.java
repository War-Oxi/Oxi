package Major.Chapter_10;

public class Shark extends Animal {
    public Shark(int h, int d, String name)   {
        super(h,d,name);
    }

    @Override 
    public void show() {
        System.out.println(name + " hp: " + hp);
    }
} 