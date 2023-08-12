// Reverse a stack using recursion

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &stack, int ele) {
    if (stack.empty()) {
        stack.push(ele);
        return;
    }
    int top = stack.top();
    stack.pop();
    insertAtBottom(stack, ele);
    stack.push(top);
}

// Function to reverse the elements of the stack
void reverseStack(stack<int> &stack) {
    if (stack.empty()) {
        return;
    }
    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, top);
}

// T : O(N^2)
// S : O(N)
