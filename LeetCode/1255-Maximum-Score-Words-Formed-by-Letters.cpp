// 1255. Maximum Score Words Formed by Letters

class Solution {
public:

    bool cantake(string s, map<char,int>& mp) {
        vector<int> f(26, 0);
        for(auto ch : s) f[ch - 'a']++;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(f[ch - 'a'] > mp[ch]) return false;
        }
        return true;
    }

    int getScore(string s, vector<int>& score) {
        int scr = 0;
        for(auto ch : s) scr += score[ch - 'a'];
        return scr;
    }

    int solve(int ind, int& n, vector<string>& words, map<char,int>& mp, vector<int>& score) {
        if(ind == n) return 0;
        string s = words[ind];
        int take = 0, nottake = 0;
        nottake = solve(ind + 1, n, words, mp, score);
        if(cantake(s, mp)) {
            for(auto ch : s) mp[ch]--;
            take = getScore(s, score) + solve(ind + 1, n, words, mp, score);
            for(auto ch : s) mp[ch]++;
        }
        return max(take, nottake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        map<char,int> mp;
        for(auto ch : letters) mp[ch]++;
        return solve(0, n, words, mp, score);
    }
};
