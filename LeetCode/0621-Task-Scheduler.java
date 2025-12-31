// 621. Task Scheduler

class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] f = new int[26];
        for (char ch : tasks) f[ch - 'A']++;

        PriorityQueue<int[]> availableTasks = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; i++) {
            if (f[i] > 0) {
                availableTasks.add(new int[]{f[i], i});
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) q.add(-1);

        int time = 0;
        int remaining = tasks.length;
        while (remaining > 0) {
            if (!availableTasks.isEmpty()) {
                q.add(availableTasks.poll()[1]);
                remaining--;
            }
            else {
                q.add(-1);
            }
            int currTask = q.poll();
            if (currTask != -1) {
                f[currTask]--;
                if (f[currTask] > 0) availableTasks.add(new int[]{f[currTask], currTask});
            }
            time++;
        }

        return time;
    }
}
