// Binary Search Trees

class Solution {
  public:
    bool isBSTTraversal(vector<int>& nums) {
        // your code here
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            if(nums[i] >= nums[i+1]) return false;
        }
        return true;
    }
};

// T : O(N)
// S : O(1)
