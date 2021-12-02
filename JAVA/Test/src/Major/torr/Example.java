package Major.torr;

public class Example {
    public static void main(String args[]) {
		Hero tor = new Hero();
		Hero rookie = new Hero();
		tor.setHP(50); //tor.HP = 50;
		tor.setPower(20); //tor.power = 20;
		rookie.setHP(40);
		rookie.setPower(15);
		rookie.Attack(tor);
		//메소드 호출로 구현: tor가 공격하여 rookie의 HP를 깎으세요
		tor.Attack(rookie);
		tor.print();
		rookie.print();
	}
}
