// 2406. Divide Intervals Into Minimum Number of Groups

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size(), ans = 0;
        sort(intervals.begin(),intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            if(!pq.empty() && pq.top() < intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
