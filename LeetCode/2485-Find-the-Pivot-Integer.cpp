// 2485. Find the Pivot Integer

class Solution {
public:
    int pivotInteger(int n) {
        int pref = 0, suff = (n * (n + 1)) / 2, st = 1;
        while(pref < suff) {
            pref += st;
            suff -= (st - 1);
            st++;
        }
        return pref == suff ? st - 1 : -1;
    }
};
