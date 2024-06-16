// 330. Patching Array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long st = 0, ptr = 0, len = nums.size();
        int patch = 0;
        while(st < n) {
            while(ptr < len && st + 1 >= nums[ptr]) {
                st += nums[ptr];
                ptr++;
            }
            if(st < n) {
                st = (2 * st) + 1;
                patch++;
            }
        }
        return patch;
    }
};
