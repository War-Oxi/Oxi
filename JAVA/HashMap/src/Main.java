// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.

import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		put();
	}

	public static void put() {
		HashMap<String, String> map = new HashMap<>();
		map.put("people", "사람");
		map.put("baseball", "야구");
		map.put("football", "미식축구");

		System.out.println(map.get("people")); // 맵의 key에 해당하는 value가 없을 경우 null이 리턴

		System.out.println(map.containsKey("people")); // 맵에 해당 key가 존재할경우 true, 없으면 false 반환

		System.out.println(map.remove("people")); // Key에 해당하는 item을 삭제 후, 그 value 값을 반환

		System.out.println(map.size()); // Map의 크기 반환

		List<String> keyList = new ArrayList<>(map.keySet()); //List 인터페이스 사용
		System.out.println(keyList);
	}
}