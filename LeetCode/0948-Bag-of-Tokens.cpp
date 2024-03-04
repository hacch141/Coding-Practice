// 948. Bag of Tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size(), l = 0, r = n - 1, c = 0, ans = 0;
        while(l <= r && power >= tokens[l]) {
            while(l < n && power >= tokens[l]) {
                power -= tokens[l++];
                c++;
            }
            ans = max(ans, c);
            if(c) {
                power += tokens[r--];
                c--;
            }
        }
        return ans;
    }
};
