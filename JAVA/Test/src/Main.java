import java.util.Scanner;

public class Main{ 
    public static void main(String args[]){
    	int i = 1;
        for(i=1 ; i<9; i=i+2){
            for(int j=1; j<9-i; j=j+2)
                System.out.print(" ");
            for(int k=1; k<=i; k++)
                System.out.print("*");
            System.out.println();
        }
        while(i>=1){
            for(int j=9; j>i; j=j-2)
                System.out.print(" ");
            for(int k=1; k<=i; k++)
                System.out.print("*");
            i=i-2;
            System.out.println();
        }
    }
}
