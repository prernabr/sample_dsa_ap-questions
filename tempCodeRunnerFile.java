class Stack {
    private int top;          // Top of the stack
    private int maxSize;      // Maximum size of the stack
    private int[] stackArray; // Array to store stack elements

    // Constructor to initialize the stack
    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1; // Initialize top as -1 to indicate an empty stack
    }

    // Method to add an element to the stack
    public void push(int value) {
        if (top == maxSize - 1) {
            System.out.println("Stack Overflow! Cannot push element " + value + ".");
            return;
        }
        stackArray[++top] = value; // Increment top and add the element to the stack
        System.out.println("Pushed element " + value + " to the stack.");
    }

    // Method to remove and return the top element from the stack
    public int pop() {
        if (top == -1) {
            System.out.println("Stack Underflow! Cannot pop element from an empty stack.");
            return -1;
        }
        int poppedElement = stackArray[top--]; // Retrieve and remove the top element
        System.out.println("Popped element " + poppedElement + " from the stack.");
        return poppedElement;
    }
}

public class Main {
    public static void main(String[] args) {
        Stack stack = new Stack(5); // Create a stack with maximum size of 5
        stack.push(10);             // Push elements onto the stack
        stack.push(20);
        stack.push(30);
        stack.pop();                // Pop an element from the stack
        stack.pop();
        stack.pop();
        stack.pop();                // Trying to pop from an empty stack
    }
}
