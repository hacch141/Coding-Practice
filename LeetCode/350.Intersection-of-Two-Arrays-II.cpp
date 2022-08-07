// 350. Intersection of Two Arrays II

class Solution {
public:
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<nums1.size(); i++) {
            mp[nums1[i]]++;
        }
        
        for(int i=0; i<nums2.size(); i++) {
            if(mp.find(nums2[i]) != mp.end()) {
                if(mp[nums2[i]]>0) {
                    ans.push_back(nums2[i]);
                    mp[nums2[i]]--;
                }
            }
        }
        return ans;
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0; i<nums1.size(); i++) {
            mp[nums1[i]]++;
        }
        for(int j=0; j<nums2.size(); j++) {
            if(mp[nums2[j]]) {
                mp[nums2[j]]--;
                ans.push_back(nums2[j]);
            }
        }
        return ans;
    }
    
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {  // 2nd Method
//         vector<int> ans;
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         int i=0, j=0;
//         while(i<nums1.size() && j<nums2.size()) {
//             if(nums1[i] == nums2[j]) {
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//             else if(nums1[i] < nums2[j]) {
//                 i++;
//             }
//             else if(nums2[j] < nums1[i]) {
//                 j++;
//             }
//         }
//         return ans;
//     }
};
