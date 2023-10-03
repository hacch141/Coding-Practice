// 905. Sort Array By Parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans = nums;
        int n = nums.size();

        int ptr = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]%2 == 0) {
                swap(ans[i],ans[ptr]);
                ptr++;
            }
        }

        return ans;
    }
};
