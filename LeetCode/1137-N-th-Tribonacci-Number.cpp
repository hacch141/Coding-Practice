// 1137. N-th Tribonacci Number

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        vector<int> a(38, 0);
        a[1] = a[2] = 1;
        for(int i = 3; i <= n; i++) {
            a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        }
        return a[n];
    }
};
