// 844. Backspace String Compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for(auto i : s) {
            if(i == '#') {
                if(!st1.empty()) st1.pop();
            }
            else {
                st1.push(i);
            }
        }

        stack<char> st2;
        for(auto i : t) {
            if(i == '#') {
                if(!st2.empty()) st2.pop();
            }
            else {
                st2.push(i);
            }
        }

        if(st1.size() != st2.size()) return false;
        
        while(!st1.empty()) {
            if(st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }

        return true;
    }
};
