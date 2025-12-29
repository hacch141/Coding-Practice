// 756. Pyramid Transition Matrix

class Solution {
    Map<String,List<Character>> mp;

    public boolean solve(int i, int j, char[][] grid) {
        if (i == j && i == 0) return true;
        if (i == j) return solve(i - 1, 0, grid);
        String base = "" + grid[i][j] + grid[i][j + 1];
        for (char ch : mp.getOrDefault(base, new ArrayList<>())) {
            grid[i - 1][j] = ch;
            if (solve(i, j + 1, grid)) return true;
        }
        return false;
    }

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        mp = new HashMap<>();
        for (String s : allowed) {
            String base = s.substring(0, 2);
            char top = s.charAt(2);
            mp.computeIfAbsent(base, k -> new ArrayList<>()).add(top);
        }
        
        int n = bottom.length();
        char[][] grid = new char[n][n];
        for (int i = 0; i < n; i++) {
            grid[n - 1][i] = bottom.charAt(i);
        }
        
        return solve(n - 1, 0, grid);
    }
}
