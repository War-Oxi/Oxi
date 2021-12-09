package Major.Chapter_9;

class Foo {
    public int x;
    public Foo(int x) {
        this.x = x;
    }
    public void setX(int x) {
        this.x = x;
}
    public int getX() {
        return x;
    }
}
	
public class Last {
    static Foo obfoo(Foo f) {
        f = new Foo(100);
        return f;
    }
    public static void main(String[] args) {
    Foo f = new Foo(300);
    System.out.print(f.getX() + "-");
    Foo ff = obfoo(f);
    System.out.print(f.getX() + "-");
    System.out.print(ff.getX() + "-");
    f = obfoo(ff);
    System.out.print(f.getX() + "-");
    System.out.print(ff.getX());
    }
}