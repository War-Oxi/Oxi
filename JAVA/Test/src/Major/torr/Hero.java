package Major.torr;

public class Hero {
    public int hp;
	private int power;
	//setHP() 메소드 구현
	public void setHP(int a) {
		hp = a;
	}
	//setPower() 메소드 구현
	public void setPower(int a) {
		power = a;
	}
	public void Attack(Hero enemy) {
		//구현 : enemy 의 hp를 본 객체의 power만큼 감소, 0이하로는 더 이상 감소하지 않는다.
		enemy.hp -= power;
		if(enemy.hp < 0)
			enemy.hp = 0;
	}
	void print() {
		System.out.printf("HP: %d, power: %d\n", hp, power);
	}
}
