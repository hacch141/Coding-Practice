// Largest Divisible Subset

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);
        int[] dp = new int[n];
        int[] prev = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            prev[i] = i;
        }
        
        int lastInd = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((1 + dp[j] > dp[i]) && nums[i] % nums[j] == 0) {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if (lastInd == -1 || dp[i] > dp[lastInd]) {
                lastInd = i;
            }
        }

        List<Integer> ans = new ArrayList<>();
        while(prev[lastInd] != lastInd) {
            ans.add(nums[lastInd]);
            lastInd = prev[lastInd];
        }
        ans.add(nums[lastInd]);
        Collections.reverse(ans);

        return ans;
    }
}
