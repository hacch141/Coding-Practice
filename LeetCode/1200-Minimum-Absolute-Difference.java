// 1200. Minimum Absolute Difference

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        int mn = Integer.MAX_VALUE;
        for (int i = 0; i < n - 1; i++) {
            mn = Math.min(mn, arr[i + 1] - arr[i]);
        }

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == mn) {
                ans.add(new ArrayList<>(Arrays.asList(arr[i], arr[i + 1])));
            }
        }

        return ans;
    }
}
