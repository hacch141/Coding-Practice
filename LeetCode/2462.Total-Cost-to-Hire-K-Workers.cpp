// 2462. Total Cost to Hire K Workers

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int low = 0;
        int high = n-1;
        priority_queue<int, vector<int>, greater<int>> lpq;
        priority_queue<int, vector<int>, greater<int>> rpq;

        long long ans = 0;
        if(2*candidates >=n) {
            for(auto i : costs) lpq.push(i);
            while(k--) {
                ans += lpq.top();
                lpq.pop();
            }
        }
        else {
            while(candidates--) {
                lpq.push(costs[low++]);
                rpq.push(costs[high--]);
            }
            while(k--) {
                int l = INT_MAX;
                int r = INT_MAX;
                if(!lpq.empty()) l = lpq.top();
                if(!rpq.empty()) r = rpq.top();

                if(l <= r) {
                    ans += lpq.top();
                    lpq.pop();
                    if(low<=high) lpq.push(costs[low++]);
                }
                else {
                    ans += rpq.top();
                    rpq.pop();
                    if(low<=high) rpq.push(costs[high--]);
                }
            }
        }
        return ans;
    }
};
