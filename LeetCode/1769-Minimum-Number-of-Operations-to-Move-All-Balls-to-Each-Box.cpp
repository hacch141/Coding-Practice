// 1769. Minimum Number of Operations to Move All Balls to Each Box

class Solution {
public:
    int get_cnt(vector<int>& f, int l, int r) {
        if(l > r) return 0;
        int cnt = f[r];
        if(l > 0) cnt -= f[l - 1];
        return cnt;
    }

    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int> left(n, 0), right(n, 0), f(n, 0);
        for(int i = 0; i < n; i++) f[i] = boxes[i] == '1';

        for(int i = 1; i < n; i++) {
            f[i] += f[i - 1];
        }

        for(int i = 0; i < n; i++) {
            if(i > 0) left[i] += left[i - 1];
            left[i] += get_cnt(f, 0, i - 1);
        }

        for(int i = n - 1; i >= 0; i--) {
            if(i + 1 < n) right[i] += right[i + 1];
            right[i] += get_cnt(f, i + 1, n - 1);
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            ans[i] = left[i] + right[i];
        }
        
        return ans;
    }
};
