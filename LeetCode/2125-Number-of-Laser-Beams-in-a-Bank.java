// 2125. Number of Laser Beams in a Bank

class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0, prev = 0, curr = 0;
        for (int i = 0; i < bank.length; i++) {
            for (int j = 0; j < bank[i].length(); j++) {
                if (bank[i].charAt(j) == '1') curr++;
            }
            ans += curr * prev;
            if (curr != 0) {
                prev = curr;
                curr = 0;
            }
        }
        return ans;
    }
}
