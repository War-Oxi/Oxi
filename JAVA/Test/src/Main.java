import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner Plus = new Scanner(System.in);
        System.out.print("input your grade : ");
        int grade = Plus.nextInt();
        if (grade >= 90){
            System.out.println("your grade is \'A\'");
        }
        else{
            System.out.println("You are loser");
        }
    }
}