// 264. Ugly Number II
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> seq(n);
        seq[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; i++) {
            seq[i] = min({2 * seq[p2], 3 * seq[p3], 5 * seq[p5]});
            if(seq[i] == 2 * seq[p2]) p2++;
            if(seq[i] == 3 * seq[p3]) p3++;
            if(seq[i] == 5 * seq[p5]) p5++;
        }
        return seq[n - 1];
    }
};
