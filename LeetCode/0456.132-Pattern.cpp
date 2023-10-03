// 456. 132 Pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> mini(n);

        mini[0] = nums[0];
        for(int i=1; i<n; i++) {
            mini[i] = min(mini[i-1],nums[i]);
        }

        for(int i=n-1; i>=1; i--) {
            while(!st.empty() && st.top() < nums[i]) {
                if(mini[i-1] < st.top()) {
                    return true;
                }
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};
