// 1685. Sum of Absolute Differences in a Sorted Array


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int total = 0;

        for(int i=0; i<n; i++) {
            total += nums[i];
        }

        int lsum=0, rsum=total;
        for(int i=0; i<n; i++) {
            rsum -= nums[i];
            int lval = (nums[i]*i) - lsum;
            int rval = rsum - (nums[i]*(n-i-1));
            lsum += nums[i];
            ans[i] += (lval + rval);
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] += (prefix[i-1] + nums[i]);
        }

        vector<int> ans(n,0);
        for(int i=1; i<n-1; i++) {
            ans[i] += ((nums[i]*i) - prefix[i-1]);
            ans[i] += ((prefix[n-1]-prefix[i]) - (nums[i]*(n-1-i)));
        }
        ans[0] = ((prefix[n-1]-prefix[0]) - (nums[0]*(n-1)));
        ans[n-1] = ((nums[n-1]*(n-1)) - prefix[n-2]);

        return ans;
    }
};
