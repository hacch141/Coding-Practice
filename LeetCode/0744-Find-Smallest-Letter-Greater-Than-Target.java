// 744. Find Smallest Letter Greater Than Target

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
        int l = 0, h = n - 1;
        char ans = letters[0];
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (letters[m] > target) {
                ans = letters[m];
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
}
