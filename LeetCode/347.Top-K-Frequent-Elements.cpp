// 347. Top K Frequent Elements

class Solution {
    
public:
    
    struct compare {
        bool operator()(pair<int,int> p1, pair<int,int> p2) {
            return p1.second < p2.second;
        }
    };
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq(mp.begin(), mp.end());
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
