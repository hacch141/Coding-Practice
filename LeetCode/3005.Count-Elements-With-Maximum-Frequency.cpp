// 3005. Count Elements With Maximum Frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx = 0, ans = 0;
        for(auto i : nums) {
            mp[i]++;
            mx = max(mx, mp[i]);
        }
        
        for(auto i : mp) {
            if(i.second == mx) ans += mx;
        }
        
        return ans;
    }
};
