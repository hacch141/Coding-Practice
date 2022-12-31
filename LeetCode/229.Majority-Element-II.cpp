// 229. Majority Element II

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1;
        int ele2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(nums[i] == ele1) {
                cnt1++;
            }
            else if(nums[i] == ele2) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                ele1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0) {
                ele2 = nums[i];
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        if(ele1 == ele2) return {ele1};
        if(cnt1 > n/3) ans.push_back(ele1);
        if(cnt2 > n/3) ans.push_back(ele2);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         vector<int> ans;
        
//         for(int i=0; i<nums.size(); i++) {
//             mp[nums[i]]++;
//         }
        
//         for(auto i : mp) {
//             if(i.second > (nums.size()/3)) {
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
//     }
// };
