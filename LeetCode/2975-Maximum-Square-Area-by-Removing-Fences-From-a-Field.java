// 2975. Maximum Square Area by Removing Fences From a Field

class Solution {
    public long MOD = (long)1e9 + 7;

    public Set<Long> getAllWidths(int m, int[] fences) {
        int n = fences.length;
        int[] newFences = new int[n + 2];
        newFences[0] = 1;
        newFences[n + 1] = m;
        for (int i = 0; i < n; i++) {
            newFences[i + 1] = fences[i];
        }

        Set<Long> st = new HashSet<>();
        for (int i = 0; i < newFences.length; i++) {
            for (int j = i + 1; j < newFences.length; j++) {
                st.add((long)newFences[j] - newFences[i]);
            }
        }

        return st;
    }

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Arrays.sort(hFences);
        Arrays.sort(vFences);
        Set<Long> stH = getAllWidths(m, hFences);
        Set<Long> stV = getAllWidths(n, vFences);

        long ans = -1;
        for (long h : stH) {
            if (stV.contains(h)) {
                ans = Math.max(ans, h * h);
            }
        }

        return (int)(ans % MOD);
    }
}

