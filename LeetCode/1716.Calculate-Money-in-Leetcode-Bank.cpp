// 1716. Calculate Money in Leetcode Bank

class Solution {
public:
    int totalMoney(int n) {
        int weeks = (n+6)/7, ans = 0;
        ans = 28;
        weeks--;
        ans += (weeks*28) + (weeks*(14+(weeks-1)*7)/2);
        int loop = 7 - n%7;
        if(loop == 7) return ans;
        for(int i=0; i<loop; i++) {
            ans -= (7-i) + weeks;
        }
        return ans;
    }
};
