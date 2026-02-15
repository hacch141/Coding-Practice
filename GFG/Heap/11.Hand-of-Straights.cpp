// Hand of Straights

class Solution {

    public boolean isNStraightHand(int[] hand, int groupSize) {

        if (hand.length % groupSize != 0)
            return false;

        TreeMap<Integer, Integer> map = new TreeMap<>();

        for (int card : hand) {
            map.put(card, map.getOrDefault(card, 0) + 1);
        }

        while (!map.isEmpty()) {

            int first = map.firstKey();
            int freq = map.get(first);   // how many groups to form

            for (int i = 0; i < groupSize; i++) {

                int curr = first + i;

                if (!map.containsKey(curr) || map.get(curr) < freq)
                    return false;

                int newCount = map.get(curr) - freq;

                if (newCount == 0)
                    map.remove(curr);
                else
                    map.put(curr, newCount);
            }
        }

        return true;
    }
}

// ============================================================================

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;

        unordered_map<int,int> mp;
        for(auto i : hand) mp[i]++;
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end());
        int n = v.size();

        for(int i=0; i<=n-groupSize; i++) {
            int freq = v[i].second;
            if(freq == 0) continue;
            for(int j=i; j<i+groupSize; j++) {
                if(j>i) { 
                    int curr = v[j].first;
                    int prev = v[j-1].first;
                    if(curr != prev + 1) return false;
                }

                if(v[j].second < freq) return false;
                v[j].second -= freq;
            }
        }

        for(auto i : v) {
            if(i.second != 0) return false;
        }
        return true;
    }
};

// T : O(N*LogN + N*groupSize)
// S : O(N)
