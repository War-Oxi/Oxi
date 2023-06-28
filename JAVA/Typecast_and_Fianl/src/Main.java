public class Main {
	public static void main(String[] args) {
		String strNum = "123";

		/* 문자열 => 정수형 변환 */
		int integerNum = Integer.parseInt(strNum); // String => Integer

		/* 정수형 => 문자열 변환 */
		strNum = String.valueOf(integerNum); // Integer => String
		strNum = Integer.toString(integerNum); // integer => String

		/* double 형 => 문자열 변환 */
		double doubleNum = Double.parseDouble(strNum); // String => double
		strNum = Double.toString(doubleNum); // double => String

		/* 정수와 실수 사이의 형 변환 */
		doubleNum = integerNum; // Integer => double에는 형 변환이 필요 없다.
		integerNum = (int)doubleNum; // double => Integer에는 형 변환이 필요하다

		final int n = 1234;
		// n = 123; => 오류 발생.
		final int n2;
		n2 = 1234; // 가능
	}
}