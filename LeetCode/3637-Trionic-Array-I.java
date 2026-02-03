// 3637. Trionic Array I

class Solution {
    public boolean isTrionic(int[] nums) {
        if (nums[0] > nums[1]) return false;

        int n = nums.length, cnt = 0;
        boolean isIncreasing = true;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return false;
            }
            else if (isIncreasing && nums[i] < nums[i - 1]) {
                isIncreasing = false;
                cnt++;
            }
            else if (!isIncreasing && nums[i] > nums[i - 1]) {
                isIncreasing = true;
                cnt++;
            }
        }

        return cnt == 2;
    }
}
