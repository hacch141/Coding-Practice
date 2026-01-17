// 3047. Find the Largest Area of Square Inside Two Rectangles

class Solution {
    public int getOverlapLine(int x1, int x2, int x11, int x22) {
        if (x2 <= x11 || x22 <= x1) return 0;
        return Math.min(x2, x22) - Math.max(x1, x11);
    }

    public long getArea(int[] bottomLeftr1, int[] topRightr1, int[] bottomLeftr2, int[] topRightr2) {
        int x1 = bottomLeftr1[0], x2 = topRightr1[0];
        int y1 = bottomLeftr1[1], y2 = topRightr1[1];
        int x11 = bottomLeftr2[0], x22 = topRightr2[0];
        int y11 = bottomLeftr2[1], y22 = topRightr2[1];

        int h = getOverlapLine(x1, x2, x11, x22);
        int v = getOverlapLine(y1, y2, y11, y22);

        int l = Math.min(h, v);
        return 1L * l * l;
    }

    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.length;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = Math.max(ans, getArea(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
            }
        }
        return ans;
    }
}
