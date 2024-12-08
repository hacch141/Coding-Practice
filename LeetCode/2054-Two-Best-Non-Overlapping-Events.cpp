// 2054. Two Best Non-Overlapping Events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size(), mx = 0, ans = 0;
        multiset<pair<int,int>> st;
        for(int i = 0; i < n; i++) {
            int start = events[i][0], end = events[i][1], val = events[i][2];
            while(!st.empty()) {
                auto it = *st.begin();
                if(it.first >= start) break;
                mx = max(mx, it.second);
                st.erase(it);
            }
            ans = max(ans, mx + val);
            st.insert({end, val});
        }
        return ans;
    }
};
