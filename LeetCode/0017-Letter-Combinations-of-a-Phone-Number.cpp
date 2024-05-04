// 17. Letter Combinations of a Phone Number

class Solution {
public:

    vector<string> tel = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int ind, int& n, string& digits, string& curr, vector<string>& comb) {
        if(ind == n) {
            if(curr.length() > 0)comb.push_back(curr); 
            return;
        }
        for(auto &ch : tel[digits[ind] - '0']) {
            curr.push_back(ch);
            solve(ind + 1, n, digits, curr, comb);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> comb;
        int n = digits.length();
        string curr = "";
        solve(0, n, digits, curr, comb);
        return comb;
    }
};
