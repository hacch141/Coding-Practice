// Implement Queue using Stack

// using 1 Stack
class MyQueue {

    Stack<Integer> stack = new Stack<>();

    // Enqueue element
    public void push(int x) {
        if (stack.isEmpty()) {
            stack.push(x);
            return;
        }

        int top = stack.pop();
        push(x);              // recursive call
        stack.push(top);      // push back old element
    }

    // Dequeue element
    public int pop() {
        if (stack.isEmpty()) return -1;
        return stack.pop();
    }

    // Front element
    public int peek() {
        if (stack.isEmpty()) return -1;
        return stack.peek();
    }

    // Check if empty
    public boolean empty() {
        return stack.isEmpty();
    }
}

// using 2 Stacks
import java.util.*;

class MyQueue {

    Stack<Integer> inStack;
    Stack<Integer> outStack;

    public MyQueue() {
        inStack = new Stack<>();
        outStack = new Stack<>();
    }

    // Enqueue
    public void push(int x) {
        inStack.push(x);
    }

    // Dequeue
    public int pop() {
        if (empty()) return -1;

        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }

        return outStack.pop();
    }

    // Front element
    public int peek() {
        if (empty()) return -1;

        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }

        return outStack.peek();
    }

    // Check if empty
    public boolean empty() {
        return inStack.isEmpty() && outStack.isEmpty();
    }
}

// ==========================================================================

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

// using 2 Stacks Optimised
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
