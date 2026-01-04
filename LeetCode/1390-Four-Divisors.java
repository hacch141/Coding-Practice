// 1390. Four Divisors

class Solution {
    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            int divisorsCount = 0, currSum = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    if (i * i != num) {
                        divisorsCount += 2;
                        currSum += i + (num / i);
                    }
                    else {
                        divisorsCount++;
                        currSum += i;
                    }
                }
            }
            if (divisorsCount == 4) ans += currSum;
        }
        return ans;
    }
}
