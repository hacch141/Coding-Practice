// 3512. Minimum Operations to Make Array Sum Divisible by K

class Solution {
    public int minOperations(int[] nums, int k) {
        int sum = 0;
        for (int i : nums) sum += i;
        return sum % k;
    }
}
