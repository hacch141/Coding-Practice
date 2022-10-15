// 451. Sort Characters By Frequency

class Solution {
public:
    
    struct compare {
        bool operator() (pair<char,int> &p1, pair<char,int> &p2) {
            return p1.second < p2.second;
        }
    };

    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto i : s) {
            mp[i]++;
        }
        
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare> pq(mp.begin(),mp.end());
        string ans = "";
        while(pq.size() != 0) {
            for(int i=0; i<pq.top().second; i++) {
                ans += pq.top().first;    
            }
            pq.pop();
        }
        
        return ans;
    }
};
