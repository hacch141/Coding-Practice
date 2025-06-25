// 2040. Kth Smallest Product of Two Sorted Arrays

class Solution {
public:
    bool ok(long long mid, long long k, vector<int>& nums1, vector<int>& nums2) {
        long long count = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        for(int i = 0; i < n1; i++) {
            int a = nums1[i];
            if (a == 0) {
                if (mid >= 0) count += n2;
            }
            else if (a > 0) {
                // Count how many b in nums2 such that a * b <= mid
                long long l = 0, h = n2 - 1, pos = -1;
                while (l <= h) {
                    long long m = (h - l) / 2 + l;
                    if (1LL * a * nums2[m] <= mid) {
                        pos = m;
                        l = m + 1;
                    } 
                    else {
                        h = m - 1;
                    }
                }
                count += (pos + 1);
            } 
            else {
                // a < 0, look for b such that a * b <= mid
                long long l = 0, h = n2 - 1, pos = n2;
                while (l <= h) {
                    long long m = (h - l) / 2 + l;
                    if (1LL * a * nums2[m] <= mid) {
                        pos = m;
                        h = m - 1;
                    } 
                    else {
                        l = m + 1;
                    }
                }
                count += (n2 - pos);
            }
        }

        return count >= k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10, h = 1e10, ans;
        while(l <= h) {
            long long m = (h - l) / 2 + l;
            if(ok(m, k, nums1, nums2)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};
