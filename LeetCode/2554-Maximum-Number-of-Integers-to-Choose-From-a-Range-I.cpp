// 2554. Maximum Number of Integers to Choose From a Range I

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0, sum = 0;
        set<int> st;
        for(auto i : banned) st.insert(i);
        for(int i = 1; i <= n; i++) {
            if(!st.count(i) && sum + i <= maxSum) {
                sum += i;
                cnt++;
            }
        }
        return cnt;
    }
};
