// 3002. Maximum Size of a Set After Removals

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> st1, st2, cmn;
        for(auto i : nums1) st1.insert(i);
        for(auto i : nums2) {
            st2.insert(i);
            if(st1.count(i)) cmn.insert(i);
        }

        int n1 = st1.size(), n2 = st2.size(), c = cmn.size();
        return min(n, min(n/2, n1 - c) + min(n/2, n2 - c) + c);
    }
};
