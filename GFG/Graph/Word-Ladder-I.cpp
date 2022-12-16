class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        s.erase(startWord);
        
        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == targetWord) {
                return step;
            }
            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(char ch= 'a'; ch<'z'; ch++) {
                    word[i] = ch;
                    if(s.find(word) != s.end()) {
                        s.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
