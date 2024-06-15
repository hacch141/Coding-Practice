// 502. IPO

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end());

        priority_queue<int> pq;
        int ptr = 0, cap = w;
        while(k--) {
            while(ptr < n && cap >= v[ptr].first) {
                pq.push(v[ptr].second);
                ptr++;
            }
            if(!pq.empty()) {
                cap += pq.top();
                pq.pop();
            }
        }
        return cap;
    }
};
