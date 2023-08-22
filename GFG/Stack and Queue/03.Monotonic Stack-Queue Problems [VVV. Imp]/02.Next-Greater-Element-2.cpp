// Next Greater Element 2

#include <bits/stdc++.h>

vector<int> nextGreaterElementII(vector<int>& a) {
    // Write your code here.
    int n = a.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=(2*n)-1; i>=0; i--) {
        while(!st.empty() && a[i%n] >= st.top()) {
            st.pop();
        }

        if(i<n) {
            if(!st.empty()) {
                ans[i] = st.top();
            }
            else {
                ans[i] = -1;
            }
        }
        st.push(a[i%n]);
    }
    return ans;
}
// T : O(2*N)
// S : O(N)
