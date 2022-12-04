package Stack;


class Circle {
    int radius;
    Circle(int radius) {
        this.radius = radius;
    }
    void show() {
        System.out.println("�������� " + radius + "�� ���̴�.");
    }
}
class ColoredCircle extends Circle {
    String color;

    ColoredCircle(int radius, String color) {
        super(radius);
        this.color=color;
    }
    void show() {
        System.out.println("�������� " + radius + "�� " + color + " ���̴�.");
    }
}

public class Stack_Main {
    public static void main(String[] args) {
        Circle c1 = new Circle(5);
        ColoredCircle c2 = new ColoredCircle(10,"������");

        c1.show();
        c2.show();
    }
}