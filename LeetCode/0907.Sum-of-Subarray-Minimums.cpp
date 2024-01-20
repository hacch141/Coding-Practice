// 907. Sum of Subarray Minimums

class Solution {
public:

    int mod = 1e9 + 7;
    vector<int> find_r(vector<int>& arr) {
        int n = arr.size();
        vector<int> r(n, 0);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            r[st.top()] = n;
            st.pop();
        }
        return r;
    }

    vector<int> find_l(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n, 0);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[i] <= arr[st.top()]) {
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            l[st.top()] = -1;
            st.pop();
        }
        return l;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> l = find_l(arr);
        vector<int> r = find_r(arr);
        long long ans = 0, lt, rt;
        for(int i=0; i<arr.size(); i++) {
            lt = abs(i - l[i]) - 1;
            rt = abs(i - r[i]) - 1;
            ans += arr[i] * (lt + 1) * (rt + 1);
            ans %= mod;
        }
        return (int)ans;
    }
};
