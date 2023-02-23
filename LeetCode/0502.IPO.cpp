// 502. IPO

class Solution {

private:
    static bool compare(pair<int,int> p1, pair<int,int> p2) {
        if(p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n = profits.size();

        for(int i=0; i<n; i++) {
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end(),compare);

        int ptr = 0;
        int maxCap = w;
        priority_queue<int, vector<int>> pq;
        int cnt = 0;

        while(cnt < k) {
            while(ptr<n && v[ptr].first <= w) {
                pq.push({v[ptr].second});
                ptr++;
            }

            if(pq.size()==0) return maxCap;
            int curr = pq.top();
            maxCap += curr;
            pq.pop();
            w += curr;
            cnt++;
        }
        return maxCap;
    }
};
