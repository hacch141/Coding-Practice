// 1569. Number of Ways to Reorder Array to Get Same BST

class Solution {
public:
    int mod = 1e9+7;

    long long dfs(vector<int>& nums, vector<vector<long long>>& nCr) {
        int n = nums.size();
        if(n <= 2) return 1;
        vector<int> leftC, rightC;
        for(int i=1; i<n; i++) {
            if(nums[i]<nums[0]) leftC.push_back(nums[i]);
            else rightC.push_back(nums[i]);
        }

        long long leftAns = dfs(leftC,nCr);
        long long rightAns = dfs(rightC,nCr);

        long long ans = (((nCr[n-1][leftC.size()] * leftAns) % mod ) * rightAns) % mod;

        return ans;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> nCr(n, vector<long long> (n,1));
        for(int i=1; i<n; i++) {
            for(int j=1; j<i; j++) {
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%mod;
            }
        }
        long long ans = dfs(nums,nCr);
        return (ans-1)%mod;
    }
};
