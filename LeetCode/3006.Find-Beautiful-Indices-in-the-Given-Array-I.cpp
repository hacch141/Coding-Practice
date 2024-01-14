// 3006. Find Beautiful Indices in the Given Array I

class Solution {
public:
    
    vector<int> stringMatch(string text, string pattern) {
	
        int n = text.length();
        int m = pattern.length();

        const long long p = 26, mod = 1e9+7;
        const long long p2 = 61, mod2 = 1e9+9;

        long long p_pow = 1;
        for(int i=1; i<=m-1; i++) {
            p_pow = (p*p_pow)%mod;
        }

        long long p_pow2 = 1;
        for(int i=1; i<=m-1; i++) {
            p_pow2 = (p2*p_pow2)%mod2;
        }

        if(m > n) return {};

        vector<int> ans;

        long long hash_pat = 0, hash_text = 0;
        long long hash_pat2 = 0, hash_text2 = 0;
        for(int i=0; i<m; i++) {
            hash_pat = ((hash_pat*p)%mod + (pattern[i]-'a'+1))%mod;
            hash_text = ((hash_text*p)%mod + (text[i]-'a'+1))%mod;

            hash_pat2 = ((hash_pat2*p2)%mod2 + (pattern[i]-'a'+1))%mod2;
            hash_text2 = ((hash_text2*p2)%mod2 + (text[i]-'a'+1))%mod2;
        }

        if(hash_pat == hash_text && hash_pat2 == hash_text2) {
            ans.push_back(0);
        }

        for(int i=0; i<n-m; i++) {
            hash_text = (hash_text - ((text[i]-'a'+1)*p_pow)%mod + mod) % mod;
            hash_text = ((hash_text*p)%mod + (text[i+m]-'a' + 1))%mod;

            hash_text2 = (hash_text2 - ((text[i]-'a'+1)*p_pow2)%mod2 + mod2) % mod2;
            hash_text2 = ((hash_text2*p2)%mod2 + (text[i+m]-'a' + 1))%mod2;

            if(hash_pat == hash_text && hash_pat2 == hash_text2) {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int> ans1 = stringMatch(s, a), ans2 = stringMatch(s, b);
        vector<int> freq(n, 0);
        for(auto i : ans2) {
            int l = max(0,i-k);
            int r = i+k+1;
            freq[l]++;
            if(r < n) freq[r]--;
        }
        for(int i=1; i<n; i++) {
            freq[i] += freq[i-1];
        }

        vector<int> ans;
        for(auto i : ans1) {
            if(freq[i] > 0) ans.push_back(i);
        }
        
        return ans;
    }
};
