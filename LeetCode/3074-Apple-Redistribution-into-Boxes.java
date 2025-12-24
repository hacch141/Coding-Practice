// 3074. Apple Redistribution into Boxes

class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int sum = 0;
        for (int i : apple) sum += i;
        Arrays.sort(capacity);
        int m = capacity.length;
        int ans = 0, p = m - 1;
        while (sum > 0) {
            sum -= capacity[p];
            ans++;
            p--;
        }
        return ans;
    }
}
