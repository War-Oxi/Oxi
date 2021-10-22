import java.util.Scanner;

public class Main{ 
    public static void main(String args[]){
        
        for(int i=1; i<=9; i=i+3){
            for(int j=1; j<=9; j++){
                for(int k=1; k<i+3; k++ ){
                    System.out.print(k + " * " + j + " = " + k*j + "\t");
                }
                System.out.println();
            }
            System.out.println("----------------------------------------");
        }
        
       
    }
}