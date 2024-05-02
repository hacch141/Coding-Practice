// 2441. Largest Positive Integer That Exists With Its Negative

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = 0;
        while(r < n && nums[r] < 0) r++;
        l = r - 1;
        int ans = -1;
        while(l >= 0 && r < n) {
            if(nums[l] + nums[r] == 0) {
                ans = nums[r];
                l--;
                r++;
            }
            else if(abs(nums[l]) < nums[r]) {
                l--;
            }
            else {
                r++;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = -1;
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                mp[nums[i]]++;
            }
            else {
                if(mp.find(-nums[i]) != mp.end()) {
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};
