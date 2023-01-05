// 493. Reverse Pairs

class Solution {

private:

    int merge(vector<int>& nums, int start, int mid, int end) {
        int cnt = 0;
        int j = mid+1;
        for(int i=start; i<=mid; i++) {
            while(j<=end && nums[i] > 2LL*nums[j]){
                j++;
            }
            cnt += j-(mid+1);
        }

        vector<int> temp;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                temp.push_back(nums[right++]);
            }
        }
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= end) temp.push_back(nums[right++]);
        for(int i=start; i<=end; i++) {
            nums[i] = temp[i-start];
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int start, int end) {
        if(start >= end) return 0;
        int mid = (start+end)/2;
        int inv = 0;
        inv += mergeSort(nums, start, mid);
        inv += mergeSort(nums, mid+1, end);
        inv += merge(nums, start, mid, end);
        return inv;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
