// Word Ladder I

import java.util.*;

class Solution {

    public int ladderLength(String startWord, String targetWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);

        // If targetWord is not present
        if (!set.contains(targetWord)) {
            return 0;
        }

        Queue<String> q = new LinkedList<>();
        q.offer(startWord);
        set.remove(startWord);

        int cnt = 1;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                String word = q.poll();
                char[] arr = word.toCharArray();

                for (int j = 0; j < arr.length; j++) {
                    char original = arr[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        arr[j] = ch;
                        String newWord = new String(arr);

                        if (set.contains(newWord)) {
                            if (newWord.equals(targetWord)) {
                                return cnt + 1;
                            }
                            q.offer(newWord);
                            set.remove(newWord);
                        }
                    }
                    arr[j] = original;
                }
            }
            cnt++;
        }
        return 0;
    }
}

// =================================================================

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        
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

// T : O(N * M * 26) N = wordList.size() M = word length of words present in the wordList
// S : O(N)
