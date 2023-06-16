// Longest String Chain

class Solution {
  public:
  
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    
    bool isValid(string& s1, string& s2) {
        if(s1.size() != 1+s2.size()) return false;
        int p1=0, p2=0;
        while(p1<s1.size()) {
            if(s1[p1]==s2[p2]) {
                p1++;
                p2++;
            }
            else {
                p1++;
            }
        }
        return p1==s1.size() && p2==s2.size();
    }

    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int ans = 1;
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<=i-1; prev++) {
                if(isValid(words[i],words[prev]) && 1+dp[prev]>dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
