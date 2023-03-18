// 532. K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(auto i : nums) {
            mp[i]++;
        }

        if(k==0) {
            for(auto i : mp) {
                if(i.second>1) ans++;
            }
            return ans;
        }

        for(auto i : mp) {
            if(mp.find(i.first-k) != mp.end()) ans++;
        }

        return ans;
    }
};
