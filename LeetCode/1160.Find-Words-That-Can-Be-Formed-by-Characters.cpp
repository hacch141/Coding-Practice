// 1160. Find Words That Can Be Formed by Characters

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(auto ch : chars) {
            freq[ch-'a']++;
        }

        int ans = 0;
        for(auto s : words) {
            vector<int> currf(26,0);
            for(auto ch : s) currf[ch-'a']++;
            bool flag = true;
            for(int i=0; i<26; i++) {
                if(currf[i] > freq[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans += s.length();
        }

        return ans;
    }
};
