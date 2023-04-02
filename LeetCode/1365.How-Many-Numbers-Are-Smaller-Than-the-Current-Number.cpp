// 1365. How Many Numbers Are Smaller Than the Current Number


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            int low = 0;
            int high = n-1;
            while(low<=high) {
                int mid = (high-low)/2 + low;
                if(temp[mid] >= nums[i]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            ans.push_back(low);
        }
        return ans;
    }
};


// =========================================================


// Brute Force
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int cnt;
        for(int i=0; i<nums.size(); i++) {
            cnt = 0;
            for(int j=0; j<nums.size(); j++) {
                if(nums[i]>nums[j]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
