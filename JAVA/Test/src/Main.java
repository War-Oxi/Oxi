import java.util.Scanner;

public class Main{ 
    public static void main(String args[]){
        int count = 3;
        int hap = 0;
        switch(count++){
            case 3 : hap = hap +count;
            case 4 : hap = hap +count;
            case 5 : hap = hap +count;
            case 6 : hap = hap + count;
        }
        System.out.println(hap);
    }
}