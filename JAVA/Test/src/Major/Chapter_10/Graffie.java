package Major.Chapter_10;

public class Graffie extends Animal {
    String name;
    public Graffie(int h, int d, String name)   {
        super(h,d);
        this.name  = name;
    }

   @Override 
   public void show() {
       System.out.println(name+" hp : " + hp);
   }
} 