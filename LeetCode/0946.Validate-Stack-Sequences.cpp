// 946. Validate Stack Sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      
        int n = pushed.size();

        stack<int> st;
        int ptr = 0;
        for(int i=0; i<n; i++) {
            st.push(pushed[i]);
            while(!st.empty() && ptr<n && st.top()==popped[ptr]) {
                st.pop();
                ptr++;
            }
        }

        return ptr==n;
    }
};
