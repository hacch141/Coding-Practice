// Maximal Rectangle

class Solution {
    public int solve(int[] heights, int n) {
        int[] leftSmaller = new int[n];
        int[] rightSmaller = new int[n];
        for (int i = 0; i < n; i++) {
            leftSmaller[i] = -1;
            rightSmaller[i] = n;
        }

        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && heights[st.peek()] > heights[i]) {
                rightSmaller[st.pop()] = i;
            }
            st.push(i);
        }

        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && heights[st.peek()] > heights[i]) {
                leftSmaller[st.pop()] = i;
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, (rightSmaller[i] - leftSmaller[i] - 1) * heights[i]);
        }

        return ans;
    }

    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length, m = matrix[0].length;

        int[][] grid = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    if (matrix[i][j] == '1') grid[i][j] = 1;
                }
                else {
                    if (matrix[i][j] == '1') {
                        grid[i][j] += 1 + grid[i - 1][j];
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, solve(grid[i], m));
        }

        return ans;
    }
}
