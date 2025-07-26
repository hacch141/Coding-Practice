// 3480. Maximize Subarrays After Removing One Conflicting Pair

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<long long>> v(n + 1, vector<long long>(2, 0));

        // finding the nearest 2 left ele which are conflicting for each i
        for(auto it : conflictingPairs) {
            int a = it[0], b = it[1];
            if(a < b) swap(a, b);
            if(b > v[a][0]) {
                v[a][1] = v[a][0];
                v[a][0] = b;
            }
            else if(b > v[a][1]) {
                v[a][1] = b;
            }
        }

        long long ans = 0, add = 0;
        long long mx = 0, mx_2 = 0;

        // if i remove ith element i can gain gains[i] number of arrays
        vector<long long> gains(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 1; j++) {
                if(v[i][j] >= mx) {
                    mx_2 = mx;
                    mx = v[i][j];
                }
                else if(v[i][j] >= mx_2) {
                    mx_2 = v[i][j];
                }
            }
            ans = ans + i - mx;
            gains[mx] += mx - mx_2;
        }

        for(auto g : gains) add = max(add, g);
        return ans + add;
    }
};
