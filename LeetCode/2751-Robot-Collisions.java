// 2751. Robot Collisions

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;

        List<int[]> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lst.add(new int[]{positions[i], healths[i], directions.charAt(i) == 'L' ? 0 : 1, i});
        }
        Collections.sort(lst, (a, b) -> Integer.compare(a[0], b[0]));

        Stack<int[]> st = new Stack<>();
        for (int[] a : lst) {
            int h = a[1];
            int dir = a[2];
            int robot = a[3];
            if (dir == 1 || st.isEmpty()) {
                st.add(new int[]{h, dir, robot});
            }
            else {
                while (!st.isEmpty() && st.peek()[1] == 1 && st.peek()[0] < h) {
                    st.pop();
                    h--;
                }
                if (!st.isEmpty() && st.peek()[1] == 1) {
                    if (st.peek()[0] == h) {
                        st.pop();
                    }
                    else {
                        st.peek()[0]--;
                    }
                    h = 0;
                }
                if (h > 0) {
                    st.add(new int[]{h, dir, robot});
                }
            }
        }

        List<int[]> tmp = new ArrayList<>(st);
        Collections.sort(tmp, (a, b) -> Integer.compare(a[2], b[2]));

        List<Integer> ans = new ArrayList<>();
        for (int[] a : tmp) {
            ans.add(a[0]);
        }

        return ans;
    }
}
