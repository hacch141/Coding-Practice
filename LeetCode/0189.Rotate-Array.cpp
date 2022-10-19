// 189. Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || n==1 || n==k) {
            return;
        }
        k = k%n;
        vector<int> temp;
        for(int i=n-1; i>=n-1-k; i--) {
            temp.push_back(nums[i]);
        }
        for(int i=n-1; i>=k; i--) {
            nums[i] = nums[i-k];
        }
        for(int i=k-1; i>=0; i--) {
            nums[i] = temp[k-i-1];
        }
    }
};
