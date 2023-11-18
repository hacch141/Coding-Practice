// 2150. Find All Lonely Numbers in the Array

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) {
            mp[i]++;
        }

        vector<int> ans;
        for(auto i : mp) {
            int num = i.first;
            int freq = i.second;
            if(freq == 1) {
                if(mp.find(num-1)==mp.end() && mp.find(num+1)==mp.end()) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};
