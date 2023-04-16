// 1639. Number of Ways to Form a Target String Given a Dictionary

class Solution {
public:

    int mod = 1e9+7;

    int helper(int i_word, vector<string>& words, int i_tar, string& target, int& n, int& w_size, int& t_size, vector<vector<int>>& dp, vector<vector<int>>& mp) {

        if(i_tar>=t_size) return 1;
        if(i_word>=w_size) return 0;
        int ans = 0;
        if(dp[i_word][i_tar]!=-1) return dp[i_word][i_tar];
        int t = 0;
        t = mp[i_word][target[i_tar]-'a'];

        ans = (helper(i_word+1,words,i_tar,target,n,w_size,t_size,dp,mp)%mod + (((long long)(t%mod)*helper(i_word+1,words,i_tar+1,target,n,w_size,t_size,dp,mp)%mod)%mod)%mod)%mod;

        dp[i_word][i_tar]=ans;
        return ans;
    }

    int numWays(vector<string>& words, string target) {

        int n = words.size();
        int t_size = target.size();
        int w_size = words[0].size();
        vector<vector<int>> dp(w_size,vector<int>(t_size,-1));
        vector<vector<int>> mp(w_size,vector<int>(26,0));

        for(int i=0; i<w_size; i++) {
            for(int j=0; j<n; j++) {
                mp[i][words[j][i]-'a']++;
            }
        }
        
        return helper(0,words,0,target,n,w_size,t_size,dp,mp);
    }
    
};
