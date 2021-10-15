public class Testfile3{
	public static void test(int y) {
		int x = 10;
		if (x == y) {
			System.out.println("두 수의 값이 같습니다");
		}
		else{
			System.out.println("두 수의 값이 다릅니다");
		}
		test(10);
	}
	
}
