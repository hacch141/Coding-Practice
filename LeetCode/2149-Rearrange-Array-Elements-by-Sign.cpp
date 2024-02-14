// 2149. Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p1 = 0, p2 = 0, n = nums.size();
        vector<int> ans;
        while(p1 < n && p2 < n) {
            while(nums[p1] < 0) p1++;
            while(nums[p2] > 0) p2++;
            ans.push_back(nums[p1]);
            ans.push_back(nums[p2]);
            p1++, p2++;
        }
        return ans;
    }
};
