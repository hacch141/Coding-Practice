// 2943. Maximize Area of Square Hole in Grid

class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int prev = -1, cnt = 0, mxH = 0, mxV = 0;
        for (int h : hBars) {
            if (prev == -1 || h == prev + 1) {
                cnt++;
            }
            else {
                mxH = Math.max(mxH, cnt + 1);
                cnt = 1;
            }
            prev = h;
        }
        mxH = Math.max(mxH, cnt + 1);
        prev = -1;
        cnt = 0;

        for (int v : vBars) {
            if (prev == -1 || v == prev + 1) {
                cnt++;
            }
            else {
                mxV = Math.max(mxV, cnt + 1);
                cnt = 1;
            }
            prev = v;
        }
        mxV = Math.max(mxV, cnt + 1);

        return Math.min(mxH, mxV) * Math.min(mxH, mxV);
    }
}
