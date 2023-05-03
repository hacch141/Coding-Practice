// 2215. Find the Difference of Two Arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto i : nums1) mp1[i]++;
        for(auto i : nums2) mp2[i]++;
        vector<vector<int>> ans(2);
        for(auto i : nums1) {
            if(mp2.find(i)==mp2.end()) {
                ans[0].push_back(i);
                mp2[i]++;
            }
        }
        for(auto i : nums2) {
            if(mp1.find(i)==mp1.end()) {
                ans[1].push_back(i);
                mp1[i]++;
            }
        }
        return ans;
    }
};
