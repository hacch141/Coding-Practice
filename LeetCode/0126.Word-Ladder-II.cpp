// 126. Word Ladder II

class Solution {
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string begin;

private:
    void dfs(string word, vector<string> &seq) {
        if(word == begin) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }

        int cnt = word.size(); 
        int steps = mp[word];
        for(int i=0; i<cnt; i++) {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word]+1==steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        begin = beginWord;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        mp[beginWord] = 1;
        int cnt = beginWord.size();

        while(!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if(word == endWord) break;
            for(int i=0; i<cnt; i++) {
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(s.find(word) != s.end()) {
                        q.push(word);
                        mp[word] = steps+1;
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if(mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
