// 3029. Minimum Time to Revert Word to Initial State I

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length(), ans = 1;
        for(int i = k; i < n; i += k) {
            bool f = true;
            for(int j = i; j < n; j++) {
                if(word[j] != word[j - i]) {
                    f = false;
                    break;
                }
            }
            if(f) return ans;
            ans++;
        }
        return ans;
    }
};
