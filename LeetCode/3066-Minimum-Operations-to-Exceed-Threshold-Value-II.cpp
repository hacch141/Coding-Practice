// 3066. Minimum Operations to Exceed Threshold Value II

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto i : nums) pq.push(i);
        int ans = 0;
        long long a, b;
        while(1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            if(a >= k) break;
            pq.push(min(a,b)*2 + max(a,b));
            ans++;
        }
        return ans;
    }
};
