// 1460. Make Two Arrays Equal by Reversing Subarrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp;
        for(auto i : arr) mp[i]++;
        for(auto i : target) {
            mp[i]--;
            if(mp[i] == 0) mp.erase(i);
        }
        return mp.empty();
    }
};
