package Major.Chapter_10;
import java.util.Scanner;
/*
public class Test {
    public static void main(String arg[]) {
        Animal tiger1 = new Tiger(10, 4, "Tiger#1");
        Animal tiger2 = new Tiger(9, 5, "Tiger#2");
        Animal shark1 = new Shark(12, 3, "Shark#1");
        tiger1.attack(tiger2); // tiger1이 tiger2를 공격
        tiger2.attack(shark1);
 
        tiger2.show();   //Tiger hp: 5
        shark1.show();  //Shark hp: 7
    }
}
*/
public class Test{
    public static void main(String args[]){
        Scanner Input = new Scanner(System.in);
        Animal Enemy = new Tiger(100, 15, "Tiger(Computer)");
        System.out.print("생성할 객체 입력 : (1.Shark 2.Tiger 3.Graffie)");
        int animal_choice = Input.nextInt();
        System.out.println("생성할 객체의 체력,데미지,이름 입력 (공백으로 구분)");
        int hp = Input.nextInt(), damage=Input.nextInt();
        String name = Input.next();
        Animal Me;
        Animal Winner;
        if(animal_choice == 1){
            Me = new Shark(hp, damage, name);
        }
        else if(animal_choice == 2){
            Me = new Tiger(hp, damage, name);
        }
        else if(animal_choice == 3){
            Me = new Graffie(hp, damage, name);
        }
        else{
            System.out.println("잘못된 값 입력");
            return;
        }

        char choice;
        while(true){
            System.out.println("c 입력 : 컴퓨터가 객체 공격 u 입력 : 내가 컴퓨터를 공격 ");
            choice = Input.next().charAt(0);
            if(choice == 'c'){
                Enemy.attack(Me);
            }
            else if(choice == 'u'){
                Me.attack(Enemy);
            }
            else{
                System.out.println("잘못된 값 입력");
                continue;
            }
            Me.show();
            Enemy.show();

            if(Me.hp <= 0 || Enemy.hp<=0){
                if(Me.hp <= 0){
                    Me.hp = 0;
                    Winner=Enemy; 
                }
                else{
                    Enemy.hp = 0;
                    Winner=Me;
                }
                System.out.println("결투가 끝났습니다.");
                System.out.println("==========================================\n승자 : " + Winner.name);
                Me.show();
                Enemy.show();
                return;
            }
        }
    }
}