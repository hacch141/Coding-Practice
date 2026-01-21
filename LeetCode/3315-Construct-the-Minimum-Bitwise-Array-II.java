// 3315. Construct the Minimum Bitwise Array II

class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int num = nums.get(i);
            if (num % 2 == 0) {
                ans[i] = -1;
            }
            else {
                int cnt = 0;
                while ((num & (1 << cnt)) != 0) {
                    ans[i] = num - (1 << cnt);
                    cnt++;
                }
            }
        }
        return ans;
    }
}
