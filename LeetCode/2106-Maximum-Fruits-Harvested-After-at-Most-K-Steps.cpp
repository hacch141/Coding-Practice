// 2106. Maximum Fruits Harvested After at Most K Steps

// Prefix sum
class Solution {
public:
    int get_freq(int l, int r, vector<int>& f) {
        int n = f.size();
        if(l > r) return 0;
        int cnt = 0;
        if(r >= 0 && r < n) cnt += f[r];
        if(l - 1 >= 0 && l - 1 < n) cnt -= f[l - 1];
        return cnt;
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int mx_x = 0;
        for(auto i : fruits) mx_x = max(mx_x, i[0]);
        vector<int> f(mx_x + 1, 0);
        for(auto i : fruits) f[i[0]] += i[1];
        for(int i = 1; i <= mx_x; i++) f[i] += f[i - 1];

        int ans = get_freq(startPos, startPos, f);
        for(int i = 1; i <= k; i++) {
            // go startPos -> right -> left -> stratPos -> left
            int l = max(0, startPos - i);
            int r = min(mx_x, startPos + ((k - i) / 2));
            ans = max(ans, get_freq(l, r, f));
            // go startPos -> left -> right -> stratPos -> right
            l = max(0, startPos - ((k - i) / 2));
            r = min(mx_x, startPos + i);
            ans = max(ans, get_freq(l, r, f));
        }
        return ans;
    }
};

// Binary
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n);
        vector<int> indices(n);

        // Build prefix sum and extract indices
        for (int i = 0; i < n; i++) {
            indices[i]   = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFrutis = 0;

        for (int d = 0; d <= k / 2; d++) {
            // Move
            int remain = k - 2 * d;
            int i   = startPos - d;
            int j  = startPos + remain;

            int left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }

            // Second case: move right x, then left (k - 2x)
            i  = startPos - remain;
            j  = startPos + d;
            
            left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }
        }

        return maxFrutis;
    }
};
