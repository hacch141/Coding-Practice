// 2402. Meeting Rooms III

class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);

        PriorityQueue<Integer> rooms = new PriorityQueue<>();
        for (int i = 0; i < n; i++) rooms.add(i);

        int[] f = new int[n];
        PriorityQueue<long[]> freeAt = new PriorityQueue<>(
            (a, b) -> {
                if (a[0] != b[0]) return Long.compare(a[0], b[0]);
                return Long.compare(a[1], b[1]);
            }
        ); // [End, room]

        for (int[] m : meetings) {
            long start = m[0], end = m[1], delay = 0;
            while (!freeAt.isEmpty() && freeAt.peek()[0] <= start) {
                rooms.add((int)freeAt.poll()[1]);
            }

            // if there are no any free rooms yet then take the first one and add that delay
            if (rooms.isEmpty()) {
                delay = freeAt.peek()[0] - start;
                rooms.add((int)freeAt.poll()[1]);
            }

            long room = rooms.poll();
            f[(int)room]++;
            freeAt.add(new long[]{end + delay, room});
        }

        int mx = Integer.MIN_VALUE, ans = -1;
        for (int i = 0; i < n; i++) {
            if (f[i] > mx) {
                mx = f[i];
                ans = i;
            }
        }
        return ans;
    }
}
