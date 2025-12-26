// 992. Subarrays with K Different Integers

class Solution {
    public int subarraysUptoKDistinct(int[] nums, int k) {
        int n = nums.length;
        int l = 0, r = 0, ans = 0;
        Map<Integer,Integer> mp = new HashMap<>();
        while (r < n) {
            mp.put(nums[r], mp.getOrDefault(nums[r], 0) + 1);
            while (mp.size() > k) {
                mp.put(nums[l], mp.get(nums[l]) - 1);
                if (mp.get(nums[l]) == 0) mp.remove(nums[l]);
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        return subarraysUptoKDistinct(nums, k) - subarraysUptoKDistinct(nums, k - 1);
    }
}
