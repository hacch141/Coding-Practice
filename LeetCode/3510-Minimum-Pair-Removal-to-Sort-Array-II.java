// 3510. Minimum Pair Removal to Sort Array II

class Solution {
    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nums[i];
        }

        int[] next = new int[n];
        int[] prev = new int[n];
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
            prev[i] = i - 1;
        }

        // <[sum, ind]>
        TreeSet<long[]> st = new TreeSet<>(
            (x, y) -> {
                if (x[0] != y[0]) return Long.compare(x[0], y[0]);
                return Long.compare(x[1], y[1]);
            }
        );

        int badCounts = 0;
        for (int i = 0; i < n - 1; i++) {
            st.add(new long[]{a[i] + a[i + 1], i});
            if (nums[i] > nums[i + 1]) badCounts++;
        }

        int ans = 0;
        while (badCounts > 0) {
            long[] curr = st.pollFirst();
            int first = (int)curr[1];
            int second = next[first];
            int leftFirst = prev[first];
            int rightSecond = next[second];

            next[first] = rightSecond;
            if (rightSecond < n) prev[rightSecond] = first;

            if (a[first] > a[second]) badCounts--;

            if (leftFirst >= 0) {
                if (a[leftFirst] > a[first] && a[leftFirst] <= a[first] + a[second]) {
                    badCounts--;
                }
                else if (a[leftFirst] <= a[first] && a[leftFirst] > a[first] + a[second]) {
                    badCounts++;
                }
            }

            if (rightSecond < n) {
                if (a[second] > a[rightSecond] && a[first] + a[second] <= a[rightSecond]) {
                    badCounts--;
                }
                else if (a[second] <= a[rightSecond] && a[first] + a[second] > a[rightSecond]) {
                    badCounts++;
                }
            }

            if (leftFirst >= 0) {
                st.remove(new long[]{a[leftFirst] + a[first], leftFirst});
                st.add(new long[]{a[leftFirst] + a[first] + a[second], leftFirst});
            }

            if (rightSecond < n) {
                st.remove(new long[]{a[second] + a[rightSecond], second});
                st.add(new long[]{a[first] + a[second] + a[rightSecond], first});
            }

            a[first] += a[second];
            ans++;
        }

        return ans;
    }
}
