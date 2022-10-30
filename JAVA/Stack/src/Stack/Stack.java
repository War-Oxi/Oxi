package Stack;

public class Stack {
	private int top = 0;
	private int size = 5;
	private int data[] = new int [5];
	
	public boolean isEmpty() {
		if (top==0)
	        return true;
	    return false;
	}
	public void push(int newdata) {
		if (top == size) {
	        System.out.print("[error] stack full\n");
	    } else {
	        data[top] = newdata;
	        top++;
	    }
	}
	public int pop() {
		if (top == 0) {
	        System.out.print("[error] stack empty\n");
	        return -1;
	    }
	    top--;
	    return data[top];
	}
}