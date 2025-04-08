// 3396. Minimum Number of Operations to Make Elements in Array Distinct

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(auto i : nums) mp[i]++;

        int ans = 0;
        if(mp.size() == n) return ans;

        for(int i = 0; i < n; i+=3) {
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            if(i + 1 < n) {
                mp[nums[i + 1]]--;
                if(mp[nums[i + 1]] == 0) mp.erase(nums[i + 1]);
            }
            if(i + 2 < n) {
                mp[nums[i + 2]]--;
                if(mp[nums[i + 2]] == 0) mp.erase(nums[i + 2]);
            }
            ans++;
            if(mp.size() == n - i - 3) return ans;
        }
        return ans;
    }
};
