// 739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                v[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            v[st.top()] = 0;
            st.pop();
        }
        return v;
    }
};
