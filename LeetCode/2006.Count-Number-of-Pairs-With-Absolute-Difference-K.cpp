// 2006. Count Number of Pairs With Absolute Difference K

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto i : nums) {
            if(mp.find(i+k) != mp.end()) ans = ans+mp[i+k];
            if(mp.find(i-k) != mp.end()) ans = ans+mp[i-k];
            mp[i]++;
        }
        return ans;
    }
};
