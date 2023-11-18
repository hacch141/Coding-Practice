// 1838. Frequency of the Most Frequent Element

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        long long int l=0, r=0, n=nums.size(), total=0, ans=0;
        for(r=0; r<n; r++) {
            total += nums[r];

            while(l<r && (nums[r]*(r-l+1) > total + k)) {
                total -= nums[l];
                l++;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
