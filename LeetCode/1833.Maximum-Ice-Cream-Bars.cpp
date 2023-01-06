// 1833. Maximum Ice Cream Bars

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
