// Printing Longest Increasing Subsequence

class Solution {
    public ArrayList<Integer> getLIS(int nums[]) {
        // Code here
        int n = nums.length;
        
        int[] dp = new int[n];
        int[] prev = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            prev[i] = i;
        }
        
        int lastInd = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if (lastInd == -1 || dp[i] > dp[lastInd]) {
                lastInd = i;
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        while (prev[lastInd] != lastInd) {
            ans.add(nums[lastInd]);
            lastInd = prev[lastInd];
        }
        ans.add(nums[lastInd]);
        
        Collections.reverse(ans);
        return ans;
    }
}
