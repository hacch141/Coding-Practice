// 368. Largest Divisible Subset

class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> lis(n, 1), prev(n, -1), ans;
        int mxLen = 0, st = -1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && 1 + lis[j] > lis[i]) {
                    lis[i] = 1 + lis[j];
                    prev[i] = j;
                }
            }
            if(lis[i] > mxLen) {
                mxLen = lis[i];
                st = i;
            }
        }

        while(st != -1) {
            ans.push_back(nums[st]);
            st = prev[st];
        }

        return ans;
    }
};
