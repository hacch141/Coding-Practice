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
        for(int i=n-k; i<n; i++) {
            temp.push_back(nums[i]);
        }
        for(int i=n-1; i>k-1; i--) {
            nums[i] = nums[i-k];
        }
        for(int i=k-1; i>=0; i--) {
            nums[i] = temp[i];
        }
    }
};

// ======================================================


    void rev(int start, int end, vector<int> &nums) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || n==1 || n==k) {
            return;
        }
        k = k%n;
        rev(0,n-k-1,nums);
        rev(n-k,n-1,nums);
        rev(0,n-1,nums);
    }
