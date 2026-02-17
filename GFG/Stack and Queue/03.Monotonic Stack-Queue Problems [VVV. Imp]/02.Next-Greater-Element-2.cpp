// Next Greater Element 2

class Solution {
    public int[] nextGreaterElements(int[] nums) {

        int n = nums.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);

        Stack<Integer> stack = new Stack<>();  // store indices

        // Traverse twice to simulate circular array
        for (int i = 0; i < 2 * n; i++) {

            int current = nums[i % n];

            // If current element is greater than element at stack top index
            while (!stack.isEmpty() && nums[stack.peek()] < current) {
                result[stack.pop()] = current;
            }

            // Only push indices during first pass
            if (i < n) {
                stack.push(i);
            }
        }

        return result;
    }
}

// ==================================================================

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
