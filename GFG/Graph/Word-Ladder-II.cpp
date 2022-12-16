class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        queue<vector<string>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord});
        vector<string> usedForLevel;
        usedForLevel.push_back(beginWord);
        int lvl = 0;
        vector<vector<string>> ans;
        
        while(!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            
            if(vec.size() > lvl) {
                lvl++;
                for(auto it : usedForLevel) {
                    s.erase(it);
                }
                usedForLevel.clear();
            }
            
            string word = vec.back();
            if(word == endWord) {
                if(ans.size()==0) {
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()) {
                    ans.push_back(vec);
                }
            }
            
            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(char ch='a'; ch<'z'; ch++) {
                    word[i] = ch;
                    if(s.find(word) != s.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        usedForLevel.push_back(word);
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};
