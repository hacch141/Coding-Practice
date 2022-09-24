// 232. Implement Queue using Stacks

class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        helper(x);
    }
    
    void helper(int x) {
        if(s.size() == 0) {
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        helper(x);
        s.push(data);
        return;
    }
    
    int pop() {
        int data = s.top();
        s.pop();
        return data;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
