import java.util.Scanner;

public class Main {
	enum option{
		SALE,
		EXIT,
		SHOW
	}

	public static void main(String[] args) {
		Cafe cafe1 = new Cafe("myCafe");
		while(true){
			option optionIn = Interface();
			boolean flag = true;
			switch(optionIn){
				case SALE -> cafe1.salesCoffee();
				case EXIT -> {
					flag = false;
					cafe1.showInfo();
				}
				case SHOW	-> cafe1.showInfo();
			}
			if(!flag) break;
		}
	}

	public static option Interface(){
		Scanner sc = new Scanner(System.in);

		System.out.println("========================================");
		System.out.println("판매: SALE || 구매: EXIT || 조회: SHOW 입력");
		System.out.println("========================================");

		option optionIn = option.valueOf(sc.next());
		if(optionIn != option.SALE && optionIn != option.EXIT && optionIn != option.SHOW){
			System.out.println("잘못된 값 입력. 다시 입력하세요");
			Interface();
		}

		return optionIn;
	}
}