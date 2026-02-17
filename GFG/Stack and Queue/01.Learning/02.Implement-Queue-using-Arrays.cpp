// Implement Queue using Arrays

class Queue {

    int[] arr;
    int start, end, currSize, maxSize;

    // Default constructor
    Queue() {
        this.maxSize = 16;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    // Parameterized constructor
    Queue(int maxSize) {
        this.maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    // Push operation
    void push(int newElement) {
        if (currSize == maxSize) {
            System.out.println("Queue is full");
            return;
        }

        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }

        arr[end] = newElement;
        currSize++;
    }

    // Pop operation
    int pop() {
        if (currSize == 0) {
            System.out.println("Queue is empty");
            return -1;
        }

        int popped = arr[start];

        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }

        currSize--;
        return popped;
    }

    // Peek operation
    int top() {
        if (currSize == 0) {
            System.out.println("Queue is empty");
            return -1;
        }
        return arr[start];
    }

    // Size
    int size() {
        return currSize;
    }

    // Check if empty
    boolean isEmpty() {
        return currSize == 0;
    }

    // Check if full
    boolean isFull() {
        return currSize == maxSize;
    }
}

// ==========================================================================

using namespace std;
class Queue {
    
    int * arr;
    int start, end, currSize, maxSize;

    public:
    Queue() {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize) {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int newElement) {
        if (currSize == maxSize) {
            cout << "Queue is full\nExiting..." << endl;
            return;
        }

        if (end == -1) {
            start = 0;
            end = 0;
        } 
        else {
            end = (end + 1) % maxSize;
        }
        arr[end] = newElement;
        cout << "The element pushed is " << newElement << endl;
        currSize++;
    }

    int pop() {
        if (start == -1 || currSize==0) {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int popped = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } 
        else {
            start = (start + 1) % maxSize;
            currSize--;
            return popped;
        }
    }

    int top() {
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }
        return arr[start];
    }

    int size() {
        return currSize;
    }

};
