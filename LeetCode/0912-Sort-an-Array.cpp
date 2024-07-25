// 912. Sort an Array

class Solution {
public:

    void merge(int low, int mid, int high, vector<int>& nums) {
        vector<int> v;
        int ptr1 = low, ptr2 = mid + 1;
        while(ptr1 <= mid && ptr2 <= high) {
            if(nums[ptr1] < nums[ptr2]) {
                v.push_back(nums[ptr1]);
                ptr1++;
            }
            else {
                v.push_back(nums[ptr2]);
                ptr2++;
            }
        }
        while(ptr1 <= mid) {
            v.push_back(nums[ptr1]);
            ptr1++;
        }
        while(ptr2 <= high) {
            v.push_back(nums[ptr2]);
            ptr2++;
        }
        for(int i = low; i <=high; i++) {
            nums[i] = v[i - low];
        }
    }

    void merge_sort(int low, int high, vector<int>& nums) {
        if(low >= high) return;
        int mid = (high - low) / 2 + low;
        merge_sort(low, mid, nums);
        merge_sort(mid + 1, high, nums);
        return merge(low, mid, high, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge_sort(0, n - 1, nums);
        return nums;
    }
};
