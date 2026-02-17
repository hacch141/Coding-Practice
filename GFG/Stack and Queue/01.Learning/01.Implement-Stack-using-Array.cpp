// Implement Stack using Array

class Stack {

    int[] arr;
    int size;
    int top;

    // Constructor
    Stack(int capacity) {
        top = -1;
        size = capacity;
        arr = new int[size];
    }

    // Push operation
    void push(int num) {
        if (top + 1 < size) {
            top++;
            arr[top] = num;
        }
        // else: stack overflow (can throw exception if needed)
    }

    // Pop operation
    int pop() {
        if (top >= 0) {
            int value = arr[top];
            top--;
            return value;
        }
        return -1; // stack underflow
    }

    // Peek (top element)
    int top() {
        if (top >= 0) {
            return arr[top];
        }
        return -1;
    }

    // Check if empty
    boolean isEmpty() {
        return top == -1;
    }

    // Check if full
    boolean isFull() {
        return top == size - 1;
    }
}

// =========================================================================

// Stack class.
class Stack {
    
public:
    int* arr;
    int size;
    int Top;
    
    Stack(int capacity) {
        // Write your code here.
        Top = -1;
        size = capacity;
        arr = new int[size];
    }

    void push(int num) {
        // Write your code here.
        if(Top+1 < size) {
            Top++;
            arr[Top] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(Top >= 0) {
            int a = arr[Top];
            Top--;
            return a;
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(Top >= 0) {
            int a = arr[Top];
            return a;
        }
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        return Top == -1;
    }
    
    int isFull() {
        // Write your code here.
        return Top == size-1;
    }
    
};
