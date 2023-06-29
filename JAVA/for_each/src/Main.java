// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
	public static void main(String[] args) {
		String[] numbers = {"one", "two", "three"};

		//for-each 사용 X
//		for(int i=0; i<numbers.length; i++) {
//			System.out.println(numbers[i]);
//		}
		// for-ecah 사용 O
		for(String number: numbers) {
			System.out.println(number);
		}
	}
}