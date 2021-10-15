package chap02;
import java.util.Scanner;

public class Testfile{
	public static void main(String[] args) {
        int a = 3;
        int b = 0;
        switch (a+2) {
            case 5: b = 1;
            default: b += 2;
        }
        System.out.println(b);
	}
}