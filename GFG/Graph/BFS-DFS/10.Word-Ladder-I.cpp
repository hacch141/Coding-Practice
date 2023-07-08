// Word Ladder I

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string> st(wordList.begin(),wordList.end());
        
        // Check if targetWord is not in wordList
        if (st.find(targetWord) == st.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(startWord);
        st.erase(startWord);
        int cnt = 1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                string s = q.front();
                q.pop();
                for(int j=0; j<s.size(); j++) {
                    char original = s[j];
                    for(char ch='a'; ch<='z'; ch++) {
                        s[j] = ch;
                        if(st.count(s)) {
                            if(s == targetWord) return 1 + cnt;
                            q.push(s);
                            st.erase(s);
                        }
                    }
                    s[j] = original;
                }
            }
            cnt++;
        }
        
        return 0;
    }
};

// T : O(N * M * 26 * LogN) N = wordList.size() M = word length of words present in the wordList
// S : O(N)
