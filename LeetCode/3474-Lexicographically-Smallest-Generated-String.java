// 3474. Lexicographically Smallest Generated String

class Solution {
    public String generateString(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) sb.append('#');

        boolean[] canChange = new boolean[N];
        for (int i = 0; i < N; i++) canChange[i] = true;

        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'T') {
                for (int j = 0; j < m; j++) {
                    if (sb.charAt(i + j) != '#' && sb.charAt(i + j) != str2.charAt(j)) {
                        return "";
                    }
                    canChange[i + j] = false;
                    sb.setCharAt(i + j, str2.charAt(j));
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (sb.charAt(i) == '#') sb.setCharAt(i, 'a');
        }

        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'F') {
                boolean f = true;
                for (int j = 0; j < m; j++) {
                    if (sb.charAt(i + j) != str2.charAt(j)) {
                        f = false;
                        break;
                    }
                }

                if (f) {
                    for (int j = m - 1; j >= 0; j--) {
                        if (canChange[i + j]) {
                            sb.setCharAt(i + j, 'b');
                            f = false;
                            break;
                        }
                    }
                }

                if (f) return "";
            }
        }

        return sb.toString();
    }
}
