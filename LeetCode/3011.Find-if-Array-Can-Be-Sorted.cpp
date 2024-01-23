// 3011. Find if Array Can Be Sorted

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(n,0);
        for(int i=0; i<n; i++) {
            bits[i] = __builtin_popcount(nums[i]);
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<i; j++) {
                if(nums[j] > nums[j+1]) {
                    if(bits[j] != bits[j+1]) return false;
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return true;
    }
};
