import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
public class Main {
    public static void main(String[] args) {
        String[] data = {"kim-tae-ji", "park-tae-hying", "kim-jin-su"};
        ArrayList<String> peoples = new ArrayList<>(Arrays.asList(data));

        peoples.sort(Comparator.naturalOrder()); // 오름차순 정렬

        System.out.println(peoples);

        peoples.sort(Comparator.reverseOrder()); // 내림차순 정렬
        System.out.println(peoples);
    }
}