// 2870. Minimum Number of Operations to Make Array Empty

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;
        
        int ans = 0;
        for(auto i : mp) {
            if(i.second == 1) return -1;
            else if(i.second%3 == 0) ans += i.second/3;
            else ans += (1 + i.second/3);
        }

        return ans;
    }
};
