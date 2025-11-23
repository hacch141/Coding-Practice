// 1262. Greatest Sum Divisible by Three

class Solution {
    public int maxSumDivThree(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        int first_1, first_2, second_1, second_2;
        if (sum % 3 == 1) {
            first_1 = first_2 = second_2 = -1;
            for (int i : nums) {
                if (i % 3 == 1 && first_1 == -1) first_1 = i;
                else if (i % 3 == 2) {
                    if (first_2 == -1) first_2 = i;
                    else if (second_2 == -1) second_2 = i;
                }
            }
            if (first_1 != -1 && first_2 != -1 && second_2 != -1) {
                sum -= Math.min(first_1, first_2 + second_2);
            }
            else if (first_1 != -1) sum -= first_1;
            else if (second_2 != -1) sum -= first_2 + second_2;
        }
        else if (sum % 3 == 2) {
            first_2 = first_1 = second_1 = -1;
            for (int i : nums) {
                if (i % 3 == 2 && first_2 == -1) first_2 = i;
                else if (i % 3 == 1) {
                    if (first_1 == -1) first_1 = i;
                    else if (second_1 == -1) second_1 = i;
                }
            }
            if (first_2 != -1 && first_1 != -1 && second_1 != -1) {
                sum -= Math.min(first_2, first_1 + second_1);
            }
            else if (first_2 != -1) sum -= first_2;
            else if (second_1 != -1) sum -= first_1 + second_1;
        }

        return sum;
    }
}


class Solution {
    public int maxSumDivThree(int[] nums) {
        int[] dp = new int[3];
        dp[1] = dp[2] = Integer.MIN_VALUE;
        for (int num : nums) {
            int[] curr = new int[3];
            System.arraycopy(dp, 0, curr, 0, 3);
            for (int i = 0; i < 3; i++) {
                curr[(i + num) % 3] = Math.max(curr[(i + num) % 3], dp[i] + num);
            }
            dp = curr;
        }
        return dp[0];
    }
}

