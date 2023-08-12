// Sort a stack

void pushAtCorrectPos(stack<int>& s, int ele) {
    if(s.empty() || ele >= s.top()) {
        s.push(ele);
        return;
    }
    
    int top = s.top();
    s.pop();
    pushAtCorrectPos(s,ele);
    s.push(top);
    return;
}

void SortedStack :: sort() {
    //Your code here
    if(s.empty()) {
       return;
    }
    int top = s.top();
    s.pop();
    sort();
    pushAtCorrectPos(s,top);
    return;
}

// T : O(N^2)
// S : O(N)
