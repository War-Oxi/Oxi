package Stack;
//import java.util.Scanner;
public class Stack_Main {
	public static void stackpop(Stack stack) {
		if (!stack.isEmpty()) {
			System.out.println(stack.pop());
		}
		else {
			System.out.println("there is no data");
		}
	}
	public static void main(String args[]) {
			Stack stack1 = new Stack();
			stack1.push(6);
			stack1.push(10);
			stack1.push(7);
			
			stackpop(stack1);
			stackpop(stack1);
			stackpop(stack1);
			stackpop(stack1);
			stackpop(stack1);
	//		if (!stack1.isEmpty()) {
	//			System.out.println(stack1.pop());
	//		}
	//		else {
	//			System.out.println("there is no data");
	//		}
	//		
	//		if (!stack1.isEmpty()) {
	//			System.out.println(stack1.pop());
	//		}
	//		else {
	//			System.out.println("there is no data");
	//		}
	//		
	//		if (!stack1.isEmpty()) {
	//			System.out.println(stack1.pop());
	//		}
	//		else {
	//			System.out.println("there is no data");
	//		}
	//		
	//		if (!stack1.isEmpty()) {
	//			System.out.println(stack1.pop());
	//		}
	//		else {
	//			System.out.println("there is no data");
	}
}