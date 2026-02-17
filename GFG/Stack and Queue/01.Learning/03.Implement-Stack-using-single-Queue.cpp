// Implement Stack using single Queue

// using 1 Queue
class MyStack {

    Queue<Integer> q;

    public MyStack() {
        q = new LinkedList<>();
    }

    // Push element onto stack
    public void push(int x) {
        q.add(x);

        // Rotate previous elements
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.add(q.remove());
        }
    }

    // Removes top element
    public int pop() {
        if (q.isEmpty()) return -1;
        return q.remove();
    }

    // Get top element
    public int top() {
        if (q.isEmpty()) return -1;
        return q.peek();
    }

    // Check if empty
    public boolean empty() {
        return q.isEmpty();
    }
}

// usgin 2 Queue (push costly)
class MyStack {

    Queue<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();

    // Push element
    public void push(int x) {

        // Step 1: Push into q2
        q2.add(x);

        // Step 2: Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.add(q1.remove());
        }

        // Step 3: Swap q1 and q2
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Pop element
    public int pop() {
        if (q1.isEmpty()) return -1;
        return q1.remove();
    }

    // Top element
    public int top() {
        if (q1.isEmpty()) return -1;
        return q1.peek();
    }

    // Check if empty
    public boolean empty() {
        return q1.isEmpty();
    }
}

// usgin 2 Queue (pop, top costly)
class MyStack {

    Queue<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();

    public void push(int x) {
        q1.add(x);
    }

    public int pop() {
        if (q1.isEmpty()) return -1;

        while (q1.size() > 1) {
            q2.add(q1.remove());
        }

        int top = q1.remove();

        // Swap queues
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;

        return top;
    }

    public int top() {
        if (q1.isEmpty()) return -1;

        while (q1.size() > 1) {
            q2.add(q1.remove());
        }

        int top = q1.peek();
        q2.add(q1.remove());

        // Swap
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;

        return top;
    }

    public boolean empty() {
        return q1.isEmpty();
    }
}

// =======================================================================

// Using Single Queueu
#include <bits/stdc++.h>

class Stack {
    // Define the data members.

   public:
    queue<int>* q;

    Stack() {
        // Implement the Constructor.
        q = new queue<int>();
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q->size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q->size() == 0;
    }

    void push(int element) {
        // Implement the push() function.
        q->push(element);
        int size = q->size();
        for (int i = 0; i < size - 1; i++) {
            q->push(q->front());
            q->pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if (q->empty()) return -1;
        int topElement = q->front();
        q->pop();
        return topElement;
    }

    int top() {
        // Implement the top() function.
        if (q->empty()) return -1;
        return q->front();
    }
};




// Using Two Queue
#include <bits/stdc++.h>

class Stack {
	// Define the data members.

   public:
    queue<int> *q1, *q2;

    Stack() {
        // Implement the Constructor.
        q1 = new queue<int>();
        q2 = new queue<int>();
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1->size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1->size() == 0;
    }

    void push(int element) {
        // Implement the push() function.
        q2->push(element);
        while(!q1->empty()) {
            q2->push(q1->front());
            q1->pop();
        }
        swap(q1,q2);
    }

    int pop() {
        // Implement the pop() function.
        if(q1->empty()) return -1;
        int a = q1->front();
        q1->pop();
        return a;
    }

    int top() {
        // Implement the top() function.
        if(q1->empty()) return -1;
        return q1->front();
    }
};
