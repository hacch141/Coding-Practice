// 3022. Minimize OR of Remaining Elements Using


class Solution {
public:
    
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int mask =  ans | ((1 << i) - 1);
            int curr = (1 << 30) - 1, cnt = 0;
            for(auto it : nums) {
                curr &= it;
                if((curr | mask) == mask) {
                    curr = (1 << 30) - 1;
                }
                else {
                    cnt++;
                }
            }
            if(cnt > k) ans |= (1 << i);
        }
        return ans;
    }
};


// ==============================================================


class Solution {
public:

    bool ok(vector<int>& nums, int& mask, int& k) {
        for(int i = 30; i >= 0; i--) {
            int curr = (1 << 30) - 1, cnt = 0;
            for(auto it : nums) {
                curr &= it;
                if((curr | mask) == mask) {
                    curr = (1 << 30) - 1;
                }
                else {
                    cnt++;
                }
            }
            if(cnt > k) return false;
        }
        return true;
    }
    
    int minOrAfterOperations(vector<int>& nums, int k) {
        int l = 0, h = INT_MAX, ans = 0;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(ok(nums, m, k)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};

