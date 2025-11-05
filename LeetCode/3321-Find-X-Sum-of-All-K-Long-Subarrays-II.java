// 3321. Find X-Sum of All K-Long Subarrays II

class Solution {
    long sum = 0;
    TreeSet<int[]> main, sec;
    Map<Integer,Integer> freq;

    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        sum = 0;

        Comparator<int[]> cmp = (a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        };

        main = new TreeSet<>(cmp);
        sec = new TreeSet<>(cmp);
        freq = new HashMap<>();

        int i = 0, j = 0;
        List<Long> ansList = new ArrayList<>();

        while (j < n) {
            int num = nums[j];
            if (freq.getOrDefault(num, 0) > 0) {
                removeFromSet(new int[]{freq.get(num), num}, x);
            }
            freq.put(num, freq.getOrDefault(num, 0) + 1);
            addInSet(new int[]{freq.get(num), num}, x);

            if (j - i + 1 == k) {
                ansList.add(sum);
                removeFromSet(new int[]{freq.get(nums[i]), nums[i]}, x);
                freq.put(nums[i], freq.get(nums[i]) - 1);
                if (freq.get(nums[i]) == 0) {
                    freq.remove(nums[i]);
                }
                else {
                    addInSet(new int[]{freq.get(nums[i]), nums[i]}, x);
                }
                i++;
            }
            j++;
        }

        long[] ans = new long[ansList.size()];
        for (int idx = 0; idx < ansList.size(); idx++) {
            ans[idx] = ansList.get(idx);
        }
        return ans;
    }

    public void addInSet(int[] p, int x) {
        if (main.size() < x || comparePair(p, main.first()) > 0) {
            main.add(p);
            sum += 1L * p[0] * p[1];
            if (main.size() > x) {
                int[] tmp = main.first();
                sum -= 1L * tmp[0] * tmp[1];
                main.remove(tmp);
                sec.add(tmp);
            }
        }
        else {
            sec.add(p);
        }
    }

    public void removeFromSet(int[] p, int x) {
        if (main.contains(p)) {
            main.remove(p);
            sum -= 1L * p[0] * p[1];

            if (!sec.isEmpty()) {
                int[] tmp = sec.last();
                sum += 1L * tmp[0] * tmp[1];
                main.add(tmp);
                sec.remove(tmp);
            }
        }
        else {
            sec.remove(p);
        }
    }

    public int comparePair(int[] a, int[] b) {
        if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
        return Integer.compare(a[1], b[1]);
    }
}
