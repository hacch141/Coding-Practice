// 641. Design Circular Deque

class MyCircularDeque {
public:
    vector<int> v;
    int l, r, len;

    MyCircularDeque(int k) {
        v.resize(2 * 2000);
        l = 2000 - 1;
        r = 2000;
        len = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        v[l] = value;
        l--;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        v[r] = value;
        r++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        l++;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        r--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return v[l + 1];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return v[r - 1];
    }
    
    bool isEmpty() {
        return r - l - 1 == 0;
    }
    
    bool isFull() {
        return r - l - 1 == len;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
