// 126. Word Ladder II

class Solution {
    Map<String,List<String>> parent;

    public void dfs(String currWord, String beginWord, List<String> path, List<List<String>> ans) {
        if (currWord.equals(beginWord)) {
            List<String> tmp = new ArrayList<>(path);
            Collections.reverse(tmp);
            ans.add(new ArrayList<>(tmp));
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
