// 2530. Maximal Score After Applying K Operations

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(auto i : nums) pq.push(i);
        while(k--) {
            ans += pq.top();
            int a = pq.top();
            pq.pop();
            pq.push((a + 2)/ 3);
        }
        return ans;
    }
};
