// 502. IPO

class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int ans=w;
        ArrayList<Pair> pairs = new ArrayList<>();
        for(int i=0;i<profits.length;i++) pairs.add(new Pair(capital[i],profits[i]));
        Collections.sort(pairs, new Sortbycap());

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        int idx =0 ;
        while(k!=0){
           while(idx < profits.length && pairs.get(idx).capital <= w){
               pq.add(pairs.get(idx).profit);
               idx++;
           }
        k--;
        if(pq.isEmpty()) return ans;
        int temp = pq.poll();
        ans+=temp;w+=temp;
       }
        return ans;
    }
}

class Sortbycap implements Comparator<Pair> {
    public int compare(Pair a, Pair b)
    {
        return a.capital-b.capital;
    }
}

class Pair{
    int profit;
    int capital; 
    Pair(int capital, int profit){
        this.capital = capital;
        this.profit = profit;
    }
}

