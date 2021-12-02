import java.util.Scanner;

class box{
    private int vol;
    public box(int w, int h, int d){
        vol = w*h*d;
    }
    public String get_vol(){
        return " 박스의 부피는 " + vol;
    }
}




public class Major{
    public static void main(String args[]){
        box mybox[] = new box[10];
        for(int i=0; i<mybox.length; i++){
            mybox[i] = new box(i*10,i*20,i*30);
        }
        for(box mb : mybox){
            System.out.println(mb.get_vol());
        }

    }
}