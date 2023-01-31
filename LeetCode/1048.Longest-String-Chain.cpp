// 1048. Longest String Chain

class Solution {

private:
    static bool compare(string& s1, string& s2) {
        return s1.length() < s2.length();
    }

    bool isSafe(string& s1, string& s2) {
        if(s1.length() != 1+s2.length()) return false;
        int first = 0;
        int second = 0;

        while(first < s1.length()) {
            if(second<s2.length() && s1[first]==s2[second]) {
                first++;
                second++;
            }
            else {
                first++;
            }
            if(first==s1.length() && second==s2.length()) return true;
        }
        return false;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size()   ;
        sort(words.begin(),words.end(),compare);
        vector<int> dp(n,1);
        int maxi = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(isSafe(words[i],words[prev]) && 1+dp[prev]>dp[i]) {
                    dp[i] = 1+dp[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }

        return maxi;
    }
};
