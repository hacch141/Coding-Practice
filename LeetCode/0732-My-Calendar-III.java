// 732. My Calendar III

class MyCalendarThree {

    TreeMap<Integer,Integer> mp;

    public MyCalendarThree() {
        mp = new TreeMap<>();
    }
    
    public int book(int startTime, int endTime) {
        mp.put(startTime, mp.getOrDefault(startTime, 0) + 1);
        mp.put(endTime, mp.getOrDefault(endTime, 0) - 1);

        int overlapEvents = 0, mx = 0;
        for (int e : mp.values()) {
            overlapEvents += e;
            mx = Math.max(mx, overlapEvents);
        }

        return mx;
    }
}
