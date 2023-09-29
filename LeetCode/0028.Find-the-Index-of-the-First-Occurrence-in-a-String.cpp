// 28. Find the Index of the First Occurrence in a String

class Solution {
public:

    bool isValid(string& a, string& b, int i, int j) {
        int n = a.length();
        int m = b.length();
        while(i<n && j<m) {
            if(a[i] != b[j]) return false;
            i++;
            j++;
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        const long long p = 26, mod = 1e9 + 7;

        long long max_pow = 1;
        for(int i=1; i<=m-1; i++) {
            max_pow = (max_pow * p) % mod;
        }

        long long hash_pat=0, hash_text=0;
        for(int i=0; i<m; i++) {
            hash_pat = ((hash_pat*p)%mod + needle[i]-'a'+1)%mod;
            hash_text = ((hash_text*p)%mod + haystack[i]-'a'+1)%mod;
        }

        if(hash_pat == hash_text) {
            if(isValid(haystack,needle,0,0)) {
                return 0;
            }
        }

        for(int i=0; i<=n-m; i++) {
            hash_text = (hash_text - ((haystack[i]-'a'+1)*max_pow)%mod + mod)%mod;
            hash_text = ((hash_text*p)%mod + haystack[i+m]-'a'+1)%mod;
            if(hash_pat == hash_text) {
                if(isValid(haystack,needle,i+1,0)) {
                    return i+1;
                }
            }
        }

        return -1;
    }
};




class Solution {

private:
    bool isValid(int start, int m, string haystack, string needle) {
        for(int i=start; i<start+m; i++) {
            if(haystack[i] != needle[i-start]) return false;
        }
        return true;
    }

public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0; i<=n-m; i++) {
            if(isValid(i,m,haystack,needle)) return i;
        }
        return -1;
    }
};
