// 1833. Maximum Ice Cream Bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int m = INT_MIN;
        for(auto it : costs) m = max(m,it);
        vector<int> v(m+1,0);
        for(auto it : costs) v[it]++;
        int ans = 0;
        for(int cost=1; cost<=m; cost++) {
            if(coins < cost) break;
            int cnt = min(v[cost],coins/cost);
            coins -= cost*cnt;
            ans += cnt;
        }
        return ans;
    }
};

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0;
        for(auto it : costs) {
            if(coins >= it) {
                coins -= it;
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int,vector<int> , greater<int>> pq(costs.begin(),costs.end());
        int ans = 0;
        while(!pq.empty() && coins >= pq.top()) {
            coins -= pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
