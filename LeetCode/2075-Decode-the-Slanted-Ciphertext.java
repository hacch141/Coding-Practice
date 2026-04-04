// 2075. Decode the Slanted Ciphertext

class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;
    
        char[][] grid = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = encodedText.charAt((i * cols) + j);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                if(i + j < cols) sb.append(grid[i][i + j]);
            }
        }
        while (!sb.isEmpty() && sb.charAt(sb.length() - 1) == ' ') sb.deleteCharAt(sb.length() - 1);

        return sb.toString();
    }
}
