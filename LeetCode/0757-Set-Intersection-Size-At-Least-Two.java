// 757. Set Intersection Size At Least Two

class Solution {
    List<Integer> lst;

    public int lower_bound(int val) {
        int n = lst.size();
        int l = 0, h = n - 1, ind = n;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (lst.get(m) >= val) {
                ind = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ind;
    }

    public int intersectionSizeTwo(int[][] intervals) {
        Comparator<int[]> cmp = (a, b) -> {
            if (a[1] != b[1]) return a[1] - b[1];
            return b[0] - a[0];
        };
        Arrays.sort(intervals, cmp);

        lst = new ArrayList<>();
        for (int[] ivl : intervals) {
            int l = ivl[0], r = ivl[1], n = lst.size();
            int ind = lower_bound(l);
            if (ind == n) {
                lst.add(r - 1);
                lst.add(r);
            }
            else if (ind == n - 1) {
                lst.add(r);
            }
        }

        return lst.size();
    }
}
