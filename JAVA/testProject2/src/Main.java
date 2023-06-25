// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList pitches;
        pitches = new ArrayList();
        pitches.add("138");
        pitches.add("129");
        pitches.add("142");
        pitches.add(123);
        pitches.add("안녕하세요");
        pitches.add(true);


        System.out.print(pitches + "\n");
        System.out.print(pitches.get(5).getClass().getName());

    }
}
