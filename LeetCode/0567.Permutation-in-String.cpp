// 567. Permutation in String

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        if(n > m) return false;

        unordered_map<char,int> mp1;
        for(auto i : s1) {
            mp1[i]++;
        }

        unordered_map<char,int> mp2;
        for(int i=0; i<n; i++) {
            mp2[s2[i]]++;
        }

        if(mp1 == mp2) return true;

        for(int i=n; i<m; i++) {
            mp2[s2[i]]++;
            mp2[s2[i-n]]--;
            if(mp2[s2[i-n]]==0) mp2.erase(s2[i-n]);
            if(mp1 == mp2) return true;
        }

        return false;
    }
};
