// 1636. Sort Array by Increasing Frequency
class Solution {
public:

    static bool cmp(pair<int,int>& p1, pair<int,int>& p2) {
        if(p1.second != p2.second) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums) mp[i]++;
        vector<pair<int,int>> v;
        for(auto i : mp) v.push_back(i);
        sort(v.begin(), v.end(), cmp);

        vector<int> ans;
        for(auto i : v) {
            for(int j = 0; j < i.second; j++) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
