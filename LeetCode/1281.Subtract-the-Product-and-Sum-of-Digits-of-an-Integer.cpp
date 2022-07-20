// 1281. Subtract the Product and Sum of Digits of an Integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1;
        int sum = 0;
        int rem = 0;
        while(n>0) {
            rem = n%10;
            sum += rem;
            mul *= rem;
            n /= 10;
        }
        return mul - sum;
    }
};
