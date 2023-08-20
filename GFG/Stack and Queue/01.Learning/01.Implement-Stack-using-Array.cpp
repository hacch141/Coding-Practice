// Implement Stack using Array

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
