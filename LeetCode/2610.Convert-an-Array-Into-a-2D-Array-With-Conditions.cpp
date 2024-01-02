// 2610. Convert an Array Into a 2D Array With Conditions

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;

        vector<vector<int>> ans;
        while(!mp.empty()) {
            vector<int> v, remove;
            for(auto& i : mp) {
                v.push_back(i.first);
                i.second--;
                if(i.second == 0) remove.push_back(i.first);
            }
            for(auto j : remove) mp.erase(j);
            ans.push_back(v);
        }

        return ans;
    }
};
