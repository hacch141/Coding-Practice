// 2448. Minimum Cost to Make Array Equal

class Solution {
public:

    long long helper(vector<int>& nums, vector<int>& cost, int& median) {
        long long ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans += 1L * abs(nums[i]-median) * cost[i];
        }
        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> v;
        int n = nums.size();
        long long total_cost = 0;
        for(int i=0; i<n; i++) {
            v.push_back({nums[i],cost[i]});
            total_cost += cost[i];
        }
        sort(v.begin(),v.end());

        int i=0;
        long long curr_cost = 0;
        int median;
        while(i<n && curr_cost<(total_cost+1)/2) {
            curr_cost += v[i].second;
            median = v[i].first;
            i++;
        }
        return helper(nums,cost,median);
    }
};
