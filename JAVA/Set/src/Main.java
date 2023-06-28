import java.util.HashSet;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		makeSet();
		getIntersection();
		getUnion();
		getSubstract();
	}

	static void makeSet(){
		HashSet<String> set = new HashSet<>(Arrays.asList("H", "E" , "L", "L", "O"));
		System.out.println(set);
	}

	static void getIntersection(){
		HashSet<Integer> s1 = new HashSet<>(Arrays.asList(1, 2, 3, 4, 5, 6));
		HashSet<Integer> s2 = new HashSet<>(Arrays.asList(4, 5, 6, 7, 8, 9));

		HashSet<Integer> intersection = new HashSet<>(s1);  // s1으로 intersection 생성
		intersection.retainAll(s2);  // 교집합 수행
		System.out.println(intersection);  // [4, 5, 6] 출력
	}

	static void getUnion(){
		HashSet<Integer> s1 = new HashSet<>(Arrays.asList(1, 2, 3, 4, 5, 6));
		HashSet<Integer> s2 = new HashSet<>(Arrays.asList(4, 5, 6, 7, 8, 9));

		HashSet<Integer> union = new HashSet<>(s1);  // s1으로 union 생성
		union.addAll(s2); // 합집합 수행
		System.out.println(union);  // [1, 2, 3, 4, 5, 6, 7, 8, 9] 출력
	}

	static void getSubstract(){
		HashSet<Integer> s1 = new HashSet<>(Arrays.asList(1, 2, 3, 4, 5, 6));
		HashSet<Integer> s2 = new HashSet<>(Arrays.asList(4, 5, 6, 7, 8, 9));

		HashSet<Integer> substract = new HashSet<>(s1);  // s1으로 substract 생성
		substract.removeAll(s2); // 차집합 수행
		System.out.println(substract);  // [1, 2, 3] 출력
	}
}