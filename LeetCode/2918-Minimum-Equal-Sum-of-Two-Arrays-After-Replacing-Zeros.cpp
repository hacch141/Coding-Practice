// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long l = 0, h = 1e10, ans = -1;
        long long s1 = 0, s2 = 0, c10 = 0, c20 = 0;

        for(auto i : nums1) {
            s1 += i;
            s1 += i == 0;
            c10 += i == 0;
        }
        for(auto i : nums2) {
            s2 += i;
            s2 += i == 0;
            c20 += i == 0;
        }

        if(s1 < s2) {
            swap(s1, s2);
            swap(c10, c20);
        }

        if(s1 > s2 && !c20) return -1;        

        return max(s1, s2);
    }
};

// ==================================================================================

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long l = 0, h = 1e10, ans = -1;
        long long s1 = 0, s2 = 0, c10 = 0, c20 = 0;

        for(auto i : nums1) {
            s1 += i;
            c10 += i == 0;
        }
        for(auto i : nums2) {
            s2 += i;
            c20 += i == 0;
        }

        if(s1 < s2) {
            swap(s1, s2);
            swap(c10, c20);
        }

        if(s1 == s2) {
            if(c10 == c20) return s1 + c10;
            else if(c10 != 0 && c20 != 0) return max(s1 + c10, s2 + c20);
            return -1;
        }

        if(c10 != 0 && c20 != 0) {
            return max(s1 + c10, s2 + c20);
        }

        if(c10 == 0 && c20 == 0) {
            return -1;
        }

        if(c10 == 0 && c20 != 0) {
            return s1 < s2 + c20 ? -1 : s1;
        }

        return -1;
    }
};
