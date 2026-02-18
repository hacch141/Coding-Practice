// Number of NGEs to the right

class Solution {

    static class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    public int[] countNGEs(int[] nums) {

        int n = nums.length;
        int[] result = new int[n];
        Pair[] arr = new Pair[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        mergeSort(arr, 0, n - 1, result);

        return result;
    }

    private void mergeSort(Pair[] arr, int left, int right, int[] result) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, result);
        mergeSort(arr, mid + 1, right, result);
        merge(arr, left, mid, right, result);
    }

    private void merge(Pair[] arr, int left, int mid, int right, int[] result) {

        List<Pair> temp = new ArrayList<>();
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {

            if (arr[i].value < arr[j].value) {
                result[arr[i].index] += (right - j + 1);
                temp.add(arr[i++]);
            } else {
                temp.add(arr[j++]);
            }
        }

        while (i <= mid) temp.add(arr[i++]);
        while (j <= right) temp.add(arr[j++]);

        for (int k = left; k <= right; k++) {
            arr[k] = temp.get(k - left);
        }
    }
}

// =================================================================================

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    // Write your code here.
    int n = arr.size();
    int m = query.size();

    vector<int> ans(m);

    for(int i=0; i<m; i++) {
        int cnt = 0;
        for(int j=query[i]+1; j<n; j++) {
            if(arr[j] > arr[query[i]]) {
                cnt++;
            }
        }
        ans[i] = cnt;
    }

    return ans;
}
// T : O(N*Q)
// S : O(1)
