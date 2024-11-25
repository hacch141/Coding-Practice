// 1652. Defuse the Bomb


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(), sum = 0;
        vector<int> ans(n, 0);
        if(k == 0) return ans;
        for(int i = 1; i <= abs(k); i++) {
            if(k < 0) {
                sum += code[(-i + n) % n];
            }
            else {
                sum += code[i];
            }
        }
        for(int i = 0; i < n; i++) {
            ans[i] = sum;
            if(k < 0) {
                sum += code[i];
                sum -= code[(i + k + n) % n];
            }
            else {
                sum -= code[(i + 1) % n];
                sum += code[(i + k + 1) % n];
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 1; j <= abs(k); j++) {
                if(k < 0) {
                    sum += code[(i - j + n) % n];
                }
                else {
                    sum += code[(i + j) % n];
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};
