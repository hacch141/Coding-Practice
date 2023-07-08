// Word Ladder II

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        queue<vector<string>> q;
        q.push({beginWord});
        st.erase(beginWord);
        
        while(!q.empty()) {
            vector<string> removeList;
            int size = q.size();
            for(int i=0; i<size; i++) {
                vector<string> v = q.front();
                q.pop();
                string s = v.back();
                
                if(s == endWord) {
                    if(ans.size() == 0) {
                        ans.push_back(v);
                    }
                    else if(ans[0].size() == v.size()) {
                        ans.push_back(v);
                    }
                }
                
                for(int j=0; j<s.size(); j++) {
                    char original = s[j];
                    for(char ch='a'; ch<='z'; ch++) {
                        s[j] = ch;
                        if(st.count(s)) {
                            v.push_back(s);
                            q.push(v);
                            v.pop_back();
                            removeList.push_back(s);
                        }
                    }
                    s[j] = original;
                }
            }
        
            for(auto i : removeList) {
                st.erase(i);
            }
        }
        
        return ans;
    }
};

// T : O(N * M * 26) N = wordList.size() M = word length of words present in the wordList
// S : O(N * M)
