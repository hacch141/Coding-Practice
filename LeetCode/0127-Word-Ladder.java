// 127. Word Ladder

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> st = new HashSet<>(wordList);

        if (!st.contains(endWord)) return 0;

        Queue<String> q = new LinkedList<>();
        q.add(beginWord);
        st.remove(beginWord);

        int lvl = 1;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                String curr = q.poll();
                char[] arr = curr.toCharArray();
                
                for (int i = 0; i < arr.length; i++) {
                    char org = arr[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        arr[i] = ch;
                        String nextStr = new String(arr);
                        System.out.println(nextStr);

                        if (st.contains(nextStr)) {
                            if (nextStr.equals(endWord)) return lvl + 1;
                            st.remove(nextStr);
                            q.add(nextStr);
                        }
                    }

                    arr[i] = org;
                }
            }
            lvl++;
        }

        return 0;
    }
}
