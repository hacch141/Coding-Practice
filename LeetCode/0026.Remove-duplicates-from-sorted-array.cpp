// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[res-1] != nums[i]) {
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> s;
//         for(int i=0; i<nums.size(); i++) {
//             s.insert(nums[i]);
//         }
//         int j = 0;
//         for(auto i : s) {
//             nums[j] = i;
//             j++;
//         }
//         return s.size();
//     }
// };
