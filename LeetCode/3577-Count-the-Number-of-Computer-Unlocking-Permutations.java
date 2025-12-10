// 3577. Count the Number of Computer Unlocking Permutations

class Solution {
    long MOD = 1_000_000_007;

    public int countPermutations(int[] complexity) {
        int n = complexity.length;
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) return 0;
        }

        long ans = 1;
        for (int i = 2; i < n; i++) ans = (ans * i) % MOD;

        return (int)ans;
    }
}
