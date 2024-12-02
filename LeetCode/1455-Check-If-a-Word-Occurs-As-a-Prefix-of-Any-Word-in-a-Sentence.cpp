// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string token;
        int cnt = 0, n = searchWord.length();
        while(ss >> token) {
            cnt++;
            if(n > token.length()) continue;
            for(int i = 0; i < n; i++) {
                if(searchWord[i] != token[i]) break;
                if(i == n - 1) return cnt;
            }
        }
        return -1;
    }
};
