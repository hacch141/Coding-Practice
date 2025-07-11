// 2402. Meeting Rooms III

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        priority_queue<int, vector<int>, greater<int>> unused;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> used;
        for(int i = 0; i < n; i++) unused.push(i);

        vector<int> cnt(n, 0);
        for(auto m : meetings) {
            long long st = m[0];
            long long end = m[1];
            while(!used.empty() && used.top().first <= st) {
                unused.push(used.top().second);
                used.pop();
            }
            if(!unused.empty()) {
                cnt[unused.top()]++;
                used.push({end, unused.top()});
                unused.pop();
            }
            else {
                long long time = used.top().first;
                int room = used.top().second;
                used.pop();
                cnt[room]++;
                used.push({end - st + time, room});
            }
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        for(int i = 0; i < n; i++) {
            if(cnt[i] == mx) return i;
        }
        return -1;
    }
};
