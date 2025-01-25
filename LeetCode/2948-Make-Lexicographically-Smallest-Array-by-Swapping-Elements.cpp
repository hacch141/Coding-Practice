// 2948. Make Lexicographically Smallest Array by Swapping Elements

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        vector<int> ind, curr;

        for(int i = 0; i < n; i++) {
            if(i == 0 || abs(v[i].first - v[i - 1].first) <= limit) {
                curr.push_back(v[i].second);
            }
            else {
                sort(curr.begin(), curr.end());
                for(auto &i : curr) ind.push_back(i);
                curr.resize(0);
                curr.push_back(v[i].second);
            }
        }

        sort(curr.begin(), curr.end());
        for(auto &i : curr) ind.push_back(i);

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[ind[i]] = v[i].first;
        }

        return ans;
    }
};
