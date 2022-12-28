class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        long long mod = 1e9 + 7;
        vector<vector<long long>> v(n);
        for(int i=0; i<n; i++) {
            v[i].resize(i+1);
            v[i][0] = 1;
            v[i][i] = 1;
            for(int j=1; j<i; j++) {
                v[i][j] = (v[i-1][j-1] + v[i-1][j])%mod;
            }
        }
        return v[n-1];
    }
};
