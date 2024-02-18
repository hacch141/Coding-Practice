// 2402. Meeting Rooms III

#define ll long long

class Solution {
public:

    static bool cpm1(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int len = meetings.size();
        vector<int> f(n, 0);
        sort(meetings.begin(), meetings.end(), cpm1);

        priority_queue<int, vector<int>, greater<int>> pqR;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pqM;

        for(int i = 0; i < n; i++) pqR.push(i);
        for(int i = 0; i < len; i++) {
            while(!pqM.empty() && pqM.top().first <= meetings[i][0]) {
                int room = pqM.top().second;
                pqM.pop();
                pqR.push(room);
            }
            if(pqR.size()) {
                int room = pqR.top();
                pqR.pop();
                pqM.push({meetings[i][1],room});
                f[room]++;
            }
            else {
                ll time = pqM.top().first;
                int room = pqM.top().second;
                pqM.pop();
                pqM.push({(ll)meetings[i][1] - (ll)meetings[i][0] + time, room});
                f[room]++;
            }
        }

        int mxf = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(f[i] > mxf) {
                ans = i;
                mxf = f[i];
            }
        }

        return ans;
    }
};
