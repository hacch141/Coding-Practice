// 3583. Count Special Triplets

class Solution {
    int MOD = 1_000_000_007;

    public int bs(int ind, List<Integer> lst) {
        int n = lst.size();
        int l = 0, h = n - 1, ans = -1;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (lst.get(m) > ind) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    public int specialTriplets(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.computeIfAbsent(nums[i], k -> new ArrayList<>());
            mp.get(nums[i]).add(i);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            int a = 2 * nums[i];
            if (nums[i] != 0 && mp.containsKey(a)) {
                List<Integer> curr = mp.get(a);
                int len = curr.size();
                int ind = bs(i, curr);
                if (ind != -1) ans = (ans + ((ind) * (len - ind))) % MOD;
            }
        }

        if (mp.containsKey(0)) {
            int len = mp.get(0).size();
            for (int i = 1; i < len - 1; i++) {
                ans = (ans + (1L * i * (len - 1 - i))) % MOD;
            }
        }

        return (int)ans;
    }
}

