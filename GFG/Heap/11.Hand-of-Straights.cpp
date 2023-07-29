// Hand of Straights

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
