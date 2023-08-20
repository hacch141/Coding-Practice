// Implement Queue using Stack

// Queue Using Only One Stack
class Queue {
    // Define the data members(if any) here.
    
    public:

    stack<int> st;
    Queue() {
        // Initialize your data structure here.
    }

    void helpToEnqueue(stack<int>& st, int ele) {
        if(st.empty()) {
            st.push(ele);
            return;
        }
        int a = st.top();
        st.pop();
        helpToEnqueue(st,ele);
        st.push(a);
        return;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        helpToEnqueue(st,val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        int a = -1;
        if(!st.empty()) {
            a = st.top();
            st.pop();
        }
        return a;
    }

    int peek() {
        // Implement the peek() function here.
        int a = -1;
        if(!st.empty()) {
            a = st.top();
        }
        return a;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st.empty();
    }
};


// Usign Two Stacks
#include <bits/stdc++.h>

class Queue {
   public:
    stack<int> st1, st2;

    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if (st1.empty()) {
            return -1; // Queue is empty.
        }
        int frontValue = st1.top();
        st1.pop();
        return frontValue;
    }

    int peek() {
        // Implement the peek() function here.
        if (st1.empty()) {
            return -1; // Queue is empty.
        }
        return st1.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st1.empty();
    }
};


// Optimised
class MyQueue {
  public:
    stack < int > input, output;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    cout << "The element pushed is " << x << endl;
    input.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();

    int x = output.top();
    output.pop();
    return x;
  }

  /** Get the front element. */
  int top() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();
    return output.top();
  }

  int size() {
    return (output.size() + input.size()); 
  }

};
