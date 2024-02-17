// 1642. Furthest Building You Can Reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0, d, i;
        for(i = 1; i < heights.size(); i++) {
            d = heights[i] - heights[i - 1];
            if(d > 0) {
                pq.push(d);
                if(pq.size() > ladders) {
                    sum += pq.top();
                    pq.pop();
                }
            }
            if(sum > bricks) break;
        }
        return i - 1;
    }
};
