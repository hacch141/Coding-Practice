// 946. Validate Stack Sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        int n = pushed.size();
        stack<int> st;
        int ptr = 0;
        
        for(auto i : pushed) {
            st.push(i);
            while(!st.empty() && st.top()==popped[ptr]) {
                st.pop();
                ptr++;
            }
        }

        return ptr==n;
    }
};
