// 2843. Count Symmetric Integers

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++) {
            int num = i;
            if(i < 100) {
                ans += i % 11 == 0;
            }
            else if(num > 999 && num < 10000) {
                int forth = num % 10;
                num /= 10;
                int third = num % 10;
                num /= 10;
                int second = num % 10;
                num /= 10;
                int first = num % 10;
                num /= 10;
                ans += first + second == third + forth;
            }
        }
        return ans;
    }
};
