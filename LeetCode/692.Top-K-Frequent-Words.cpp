// 692. Top K Frequent Words

class Solution {
public:
    
    struct compare {
        bool operator()(pair<string,int> &p1, pair<string,int> &p2) {
            if(p1.second == p2.second) {
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto i : words) {
            mp[i]++;
        }
        priority_queue<pair<string,int>, vector<pair<string,int>>, compare> pq(mp.begin(),mp.end());
        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
