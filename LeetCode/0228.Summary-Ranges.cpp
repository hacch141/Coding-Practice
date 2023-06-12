// 228. Summary Ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        string s = "";
        for(int i=0; i<n; i++) {
            int j = i;
            while(j+1<n && nums[j+1] == 1+nums[j]) j++;
            if(i==j) {
                ans.push_back(to_string(nums[i]));
            }
            else {
                ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            }
            i = j;
        }
        return ans;
    }
};
