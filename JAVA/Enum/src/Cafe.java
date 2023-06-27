import java.util.Objects;
import java.util.Scanner;

enum CoffeeType {
	AMERICANO, ICE_AMERICANO, CAFE_LATTE
}

public class Cafe {
	String name;
	int americanoSalesCount = 0;
	int iceAmericanoSalesCount = 0;
	int cafeLatteSalesCount = 0;

	Cafe(String name) {
		this.name = name;
	}

	Cafe(String name, int americanoCurSalesCount, int iceAmericanoCurSalesCount, int cafeLatteCurSalesCount) {
		this.name = name;
		this.americanoSalesCount = americanoCurSalesCount;
		this.iceAmericanoSalesCount = iceAmericanoCurSalesCount;
		this.cafeLatteSalesCount = cafeLatteCurSalesCount;
	}

	public void salesCoffee() {
		Scanner sc = new Scanner(System.in);

		CoffeeType option = null;
		System.out.println("========================================");
		System.out.println("1. AMERICANO, 2. ICE_AMERICANO, 3.CAFE_LATTE");
		System.out.println("========================================");
		System.out.print("판 커피의 종류는? (제품명 입력) => ");
		try{
			option = CoffeeType.valueOf(sc.next());
		}catch(Exception e){
			System.out.println("제품명을 잘못 입력했습니다. 다시 입력해주세요.");
			salesCoffee();
			return;
		}

		int salesCount = 0;
		System.out.println("========================================");
		System.out.print("판 커피의 개수는? (숫자 입력) => ");
		try{
			salesCount = sc.nextInt();
		}catch(Exception e){
			System.out.println("판 커피의 개수을 잘못 입력했습니다. 다시 입력해주세요.");
			salesCoffee();
			return;
		}

		switch (Objects.requireNonNull(option)) {
			case AMERICANO -> americanoSalesCount += salesCount;
			case ICE_AMERICANO -> iceAmericanoSalesCount += salesCount;
			case CAFE_LATTE -> cafeLatteSalesCount += salesCount;
			default -> System.out.println("Wrong value restart");
		}

		showInfo();
	}
	public void showInfo(){
		System.out.println("========================================");
		System.out.printf("아메리카노 판매량 : %d 매출액 : %d \n", americanoSalesCount, americanoSalesCount * 3000);
		System.out.printf("아메리카노 판매량 : %d 매출액 : %d \n", iceAmericanoSalesCount, iceAmericanoSalesCount * 4000);
		System.out.printf("아메리카노 판매량 : %d 매출액 : %d \n", cafeLatteSalesCount, cafeLatteSalesCount * 5000);
	}
}
