// 520. Detect Capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]>='a' && word[0]<='z') {
            for(auto i : word) {
                if(i<'a' || i>'z') return false;
            }
        }
        else if(word[0]>='A' && word[0]<='Z' && word[1]>='A' && word[1]<='Z') {
            for(auto i : word) {
                if(i<'A' || i>'Z') return false;
            }
        }
        else if(word[0]>='A' && word[0]<='Z' && word[1]>='a' && word[1]<='z') {
            for(int i=2; i<word.length(); i++) {
                if(word[i]<'a' || word[i]>'z') return false;
            }
        }
        return true;
    }
};
