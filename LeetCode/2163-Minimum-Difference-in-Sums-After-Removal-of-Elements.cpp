// 2163. Minimum Difference in Sums After Removal of Elements

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> l, r;

        priority_queue<int> pq_mx;
        long long l_sum = 0;
        for(int i = 0; i < n; i++) {
            pq_mx.push(nums[i]);
            l_sum += nums[i];
        }
        l.push_back(l_sum);

        for(int i = n; i < 2 * n; i++) {
            pq_mx.push(nums[i]);
            l_sum += nums[i];
            l_sum -= pq_mx.top(); 
            pq_mx.pop();
            l.push_back(l_sum);
        }

        long long r_sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq_mn;
        for(int i = 3 * n - 1; i >= 2 * n; i--) {
            pq_mn.push(nums[i]);
            r_sum += nums[i];
        }
        r.push_back(r_sum);

        for(int i = 2 * n - 1; i >= n; i--) {
            pq_mn.push(nums[i]);
            r_sum += nums[i];
            r_sum -= pq_mn.top();
            pq_mn.pop();
            r.push_back(r_sum);
        }
        reverse(r.begin(), r.end());

        long long ans = LLONG_MAX;
        for(int i = 0; i <= n; i++) {
            ans = min(ans, l[i] - r[i]);
        }
        return ans;
    }
};
