// 779. K-th Symbol in Grammar

class Solution {
public:
    int solve(int n, int k) {
        if(k == 1) return 0;
        int len = 1, newK;
        for(int i = 0; i < n; i++) {
            len = 2 * len;
            if(len >= k) {
                newK = k - (len / 2);
                break;
            }
        }
        int grammer = solve(n, newK);
        return !grammer;
    }

    int kthGrammar(int n, int k) {
        return solve(n, k);
    }
};
