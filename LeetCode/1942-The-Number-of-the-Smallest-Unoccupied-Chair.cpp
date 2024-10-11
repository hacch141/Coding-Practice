// 1942. The Number of the Smallest Unoccupied Chair

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size(), ans;
        priority_queue<int, vector<int>, greater<int>> pq_mn;
        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i].push_back(times[i][0]);
            v[i].push_back(times[i][1]);
            v[i].push_back(i);
        }
        sort(v.begin(),v.end());
        for(int i = 0; i < n; i++) pq_mn.push(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && pq.top().first <= v[i][0]) {
                pq_mn.push(pq.top().second);
                pq.pop();
            }
            if(v[i][2] == targetFriend) ans = pq_mn.top();
            pq.push({v[i][1], pq_mn.top()});
            pq_mn.pop();
        }
        return ans;
    }
};
