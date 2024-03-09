// 2540. Minimum Common Value

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), j = 0;
        for(int i = 0; i < n1; i++) {
            while(j < n2 && nums1[i] > nums2[j]) {
                j++;
            }
            if(j < n2 && nums1[i] == nums2[j]) return nums1[i];
        }
        return -1;
    }
};
