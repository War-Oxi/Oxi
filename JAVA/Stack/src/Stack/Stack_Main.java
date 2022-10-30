package Stack;

public class Stack_Main {
	public static void main(String args[]) {
		Stack stack1 = new Stack();
		stack1.push(6);
		stack1.push(10);
		stack1.push(7);

	    if (!stack1.isEmpty())
	        System.out.printf("%d\n", stack1.pop());
	    
	    if (!stack1.isEmpty())
	    	System.out.printf("%d\n", stack1.pop());
	    
	    if (!stack1.isEmpty())
	    	System.out.printf("%d\n", stack1.pop());
	    
	    if (!stack1.isEmpty())
	    	System.out.printf("%d\n", stack1.pop());		    
	    else
	    	System.out.printf("%d\n", stack1.pop());		    
	}
}