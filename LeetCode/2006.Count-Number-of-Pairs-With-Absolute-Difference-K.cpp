// 2006. Count Number of Pairs With Absolute Difference K

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(auto i : nums) {
            mp[i]++;
        }

        for(auto i : mp) {
            if(mp.find(i.first-k) != mp.end()) {
                ans += mp[i.first-k]*mp[i.first];
            }
        }
        
        return ans;
    }
};
