package Major.Chapter_10;

public class Graffie extends Animal {
    public Graffie(int h, int d, String name)   {
        super(h,d,name);
    }

   @Override 
   public void show() {
       System.out.println(name+" hp : " + hp);
   }
} 