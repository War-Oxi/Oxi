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
	        System.out.println("[error] stack full");
	    } else {
	        data[top] = newdata;
	        top++;
	    }
	}
	public int pop() {
		if (top == 0) {
	        System.out.println("[error] stack empty");
	        return 0;
	    }
	    top--;
	    return data[top];
	}
}
