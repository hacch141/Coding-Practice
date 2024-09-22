// 386. Lexicographical Numbers

class Solution {
public:

    void rec(int num, int& n, vector<int>& ans) {
        if(num > n) return;
        if(num != 0) ans.push_back(num);
        for(int i = 0; i <= 9; i++) {
            if(num == 0 && i == 0) continue;
            rec(num * 10 + i, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        rec(0, n, ans);
        return ans;
    }
};
