// Word Ladder II

class Solution {
    Map<String,List<String>> parent;

    public void dfs(String currWord, String beginWord, List<String> path, List<List<String>> ans) {
        if (currWord.equals(beginWord)) {
            List<String> tmp = new ArrayList<>(path);
            Collections.reverse(tmp);
            ans.add(tmp);
            return;
        }

        for (String prev : parent.get(currWord)) {
            path.add(prev);
            dfs(prev, beginWord, path, ans);
            path.remove(path.size() - 1);
        }
    }

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> st = new HashSet<>(wordList);
        List<List<String>> ans = new ArrayList<>();
        parent = new HashMap<>();

        if (!st.contains(endWord)) return ans;

        Queue<String> q = new LinkedList<>();
        q.add(beginWord);
        st.remove(beginWord);

        while (!q.isEmpty()) {
            int sz = q.size();
            Set<String> removeStr = new HashSet<>();
            while (sz-- > 0) {
                String curr = q.poll();
                char[] arr = curr.toCharArray();
                for (int i = 0; i < arr.length; i++) {
                    char org = arr[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        arr[i] = ch;
                        String nextStr = new String(arr);
                        if (!st.contains(nextStr)) continue;
                        if (!removeStr.contains(nextStr)) {
                            q.add(nextStr);
                            removeStr.add(nextStr);
                        }
                        parent.computeIfAbsent(nextStr, k -> new ArrayList<>()).add(curr);
                    }
                    arr[i] = org;
                }
            }
            st.removeAll(removeStr);
        }

        if (!parent.containsKey(endWord)) return ans;

        List<String> path = new ArrayList<>(Arrays.asList(endWord));
        dfs(endWord, beginWord, path, ans);
    
        return ans;
    }
}

// TLE in java
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> st = new HashSet<>(wordList);
        List<List<String>> ans = new ArrayList<>();

        Queue<List<String>> q = new LinkedList<>();
        q.add(new ArrayList<>(Arrays.asList(beginWord)));

        while (!q.isEmpty()) {
            int sz = q.size();
            List<String> removeList = new ArrayList<>();
            while (sz-- > 0) {
                List<String> curr = q.poll();

                String last = curr.get(curr.size() - 1);
                if (last.equals(endWord)) {
                    if (ans.size() == 0) {
                        ans.add(new ArrayList<>(curr));
                    }
                    else if (ans.get(0).size() == curr.size()) {
                        ans.add(new ArrayList<>(curr));
                    }
                }

                char[] arr = last.toCharArray();
                for (int i = 0; i < arr.length; i++) {
                    char org = arr[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        arr[i] = ch;
                        String nextStr = new String(arr);
                        if (st.contains(nextStr)) {
                            curr.add(nextStr);
                            q.add(new ArrayList<>(curr));
                            curr.remove(curr.size() - 1);
                            removeList.add(nextStr);
                        }
                    }
                    arr[i] = org;
                }
            }
            for (String s : removeList) {
                st.remove(s);
            }
        }

        return ans;
    }
}

// =================================================================================================

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
