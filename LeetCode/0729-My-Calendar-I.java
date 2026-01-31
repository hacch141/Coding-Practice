// 729. My Calendar I

class MyCalendar {
    TreeMap<Integer,Integer> mp;

    public MyCalendar() {
        mp = new TreeMap<>();
    }
    
    public boolean book(int startTime, int endTime) {
        int events = 0;
        mp.put(startTime, mp.getOrDefault(startTime, 0) + 1);
        mp.put(endTime, mp.getOrDefault(endTime, 0) - 1);
        for (int del : mp.values()) {
            events += del;
            if (events > 1) {
                mp.put(startTime, mp.get(startTime) - 1);
                mp.put(endTime, mp.get(endTime) + 1);
                return false;
            }
        }
        return true;
    }
}
