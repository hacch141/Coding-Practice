// 3013. Divide an Array Into Subarrays With Minimum Cost II

class Solution {
    TreeMap<Integer,Integer> mp1;
    TreeMap<Integer,Integer> mp2;
    int sz1, sz2, K;
    long currSum, ans;

    public void add(int num) {
        mp1.put(num, mp1.getOrDefault(num, 0) + 1);
        currSum += (long)num;
        sz1++;
        while (sz1 > K - 1) {
            int mxFromMp1 = mp1.lastKey();

            mp1.put(mxFromMp1, mp1.get(mxFromMp1) - 1);
            if (mp1.get(mxFromMp1) == 0) mp1.remove(mxFromMp1);
            currSum -= mxFromMp1;
            sz1--;

            mp2.put(mxFromMp1, mp2.getOrDefault(mxFromMp1, 0) + 1);
            sz2++;
        }
    }

    public void remove(int num) {
        if (mp2.containsKey(num)) {
            mp2.put(num, mp2.get(num) - 1);
            if (mp2.get(num) == 0) mp2.remove(num);
            sz2--;
        }
        else {
            mp1.put(num, mp1.get(num) - 1);
            if (mp1.get(num) == 0) mp1.remove(num);
            currSum -= num;
            sz1--;
        }
        while (sz1 < K - 1) {
            int mnFromMp2 = mp2.firstKey();

            mp2.put(mnFromMp2, mp2.get(mnFromMp2) - 1);
            if (mp2.get(mnFromMp2) == 0) mp2.remove(mnFromMp2);
            sz2--;

            mp1.put(mnFromMp2, mp1.getOrDefault(mnFromMp2, 0) + 1);
            currSum += mnFromMp2;
            sz1++;
        }
    }

    public long minimumCost(int[] nums, int k, int dist) {
        int n = nums.length;
        K = k;

        mp1 = new TreeMap<>();
        mp2 = new TreeMap<>();
        sz1 = 0;
        sz2 = 0;
        currSum = 0L;

        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }
        ans = currSum;

        for (int i = dist + 2; i < n; i++) {
            add(nums[i]);
            remove(nums[i - dist - 1]);
            ans = Math.min(ans, currSum);
        }

        return ans + nums[0];
    }
}

