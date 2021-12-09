package Major.Chapter_9;
import java.util.Scanner;

public class Major_Compare{
    public static void main(String args[]){
        Scanner Num = new Scanner(System.in); 
        Major_Compare Max = new Major_Compare();
        
        System.out.print("정수를 비교하시겠습니까 실수를 비교하시겠습니까?(정수: 1, 실수: 2)");
        int selection = Num.nextInt();
        System.out.print("비교 두 수를 입력하세요(공백으로 구분) : ");
        if(selection == 1){
            int integer_num_a = Num.nextInt();
            int integer_num_b = Num.nextInt();
            System.out.println("큰 수 : " + Max.Compare(integer_num_a, integer_num_b));
        }
        else{
            double real_num_a = Num.nextDouble();
            double real_num_b = Num.nextDouble();
            System.out.println("큰 수 : " + Max.Compare(real_num_a,real_num_b));
        }
        Num.close();
    }
    public int Compare(int a, int b){
        int result;
        if(a<b){
            result = b;
        }
        else{
            result = a;
        }
        return result;
    }
    public double Compare(double a, double b){
        double result;
        if(a<b){
            result = b;
        }
        else{
            result = a;
        }
        return result;
    }   
}