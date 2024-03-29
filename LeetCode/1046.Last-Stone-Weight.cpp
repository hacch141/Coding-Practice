// 1046. Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i : stones) {
            pq.push(i);
        }

        while(pq.size()>1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a!=b) {
                pq.push(abs(a-b));
            }
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};
