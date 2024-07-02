// 350. Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size(), n2 = nums2.size(), p1 = 0, p2 = 0;
        vector<int> ans;
        while(p1 < n1 && p2 < n2) {
            if(nums1[p1] == nums2[p2]) {
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1] < nums2[p2]) {
                p1++;
            }
            else {
                p2++;
            }
        }
        return ans;
    }
};
