// 3014. Minimum Number of Pushes to Type Word I

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        int ans = 0;
        for(auto i : word) freq[i-'a']++;
        sort(freq.rbegin(),freq.rend());
        int p = 0;
        for(int i=0; i<8; i++) ans += freq[i];
        for(int i=8; i<16; i++) ans += 2*freq[i];
        for(int i=16; i<24; i++) ans += 3*freq[i];
        for(int i=24; i<26; i++) ans += 4*freq[i];
        return ans;
    }
};
