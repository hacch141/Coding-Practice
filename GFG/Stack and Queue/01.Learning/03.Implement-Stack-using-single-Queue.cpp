// Implement Stack using single Queue


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
