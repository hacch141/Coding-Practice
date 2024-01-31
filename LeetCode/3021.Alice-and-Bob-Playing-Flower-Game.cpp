// 3021. Alice and Bob Playing Flower Game

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        long long odd1 = n / 2 + n % 2, eve1 = n / 2;
        long long odd2 = m / 2 + m % 2, eve2 = m / 2;
        return (odd1 * eve2) + (odd2 * eve1);
    }
};
