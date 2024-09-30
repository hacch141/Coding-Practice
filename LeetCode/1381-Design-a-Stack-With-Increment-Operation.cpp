// 1381. Design a Stack With Increment Operation

class CustomStack {
public:
    vector<int> v;
    int ptr = 0, mx;
    CustomStack(int maxSize) {
        v.resize(maxSize);
        mx = maxSize;
    }
    
    void push(int x) {
        if(ptr == mx) return;
        v[ptr] = x;
        ptr++;
    }
    
    int pop() {
        if(ptr == 0) return -1;
        ptr--;
        int ele = v[ptr];
        return ele;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, mx); i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
