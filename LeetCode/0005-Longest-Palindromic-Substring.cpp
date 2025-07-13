// 5. Longest Palindromic Substring

// Two Pointer
class Solution {
public:
    string find(string s, int left, int right) {
        int n = s.length();
        while(left>=0 && right<n && s[left]==s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i=0; i<n; i++) {
            // find largest odd len pal with centered i
            string a = find(s,i,i);
            if(a.length() > ans.length()) ans = a;
            // find largest even len pal with centered i, i + 1
            string b = find(s,i,i+1);
            if(b.length() > ans.length()) ans = b;
        }

        return ans;
    }
};

// Rec
class Solution {
public:
    bool is_palindrome(string& s, int l, int r, vector<vector<int>>& dp) {
        if(l >= r) return true;

        if(dp[l][r] != -1) return dp[l][r];

        return dp[l][r] = s[l] == s[r] ? is_palindrome(s, l + 1, r - 1, dp) : false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        string ans = "";
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(is_palindrome(s, i, j, dp) && (j - i + 1 > ans.length())) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;
    }
};
