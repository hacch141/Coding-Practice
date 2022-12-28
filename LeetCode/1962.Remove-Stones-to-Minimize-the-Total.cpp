// 1962. Remove Stones to Minimize the Total

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto i : piles) {
            pq.push(i);
        }
        
        for(int i=0; i<k; i++) {
            float a = pq.top(); 
            pq.pop();
            pq.push((int)a-floor(a/2));
        }

        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
