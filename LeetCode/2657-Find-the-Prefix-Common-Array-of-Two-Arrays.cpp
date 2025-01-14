// 2657. Find the Prefix Common Array of Two Arrays

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int> f(n + 1, 0), ans(n);
        for(int i = 0; i < n; i++) {
            f[A[i]]++;
            f[B[i]]++;
            cnt += f[A[i]] == 2;
            cnt += f[B[i]] == 2;
            cnt -= A[i] == B[i];
            ans[i] = cnt;
        }
        return ans;
    }
};
