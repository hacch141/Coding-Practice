// Task Scheduler

struct compare {
    bool operator()(pair<char,int>& p1, pair<char,int>& p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto i : tasks) {
            mp[i]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare> pq(mp.begin(),mp.end());
        queue<pair<int,pair<char,int>>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time += 1;
            if(!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                it.second--;
                if(it.second >= 1) {
                    q.push({time,it});
                }
            }
            if(!q.empty() && time >= q.front().first+n) {
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};

// T : O(N * LogN)
// S : O(N)


#include <bits/stdc++.h> 
int taskScheduler(string tasks, int n, int t) {
    // Write your code here
    unordered_map<char,int> mp;
    int maxi = INT_MIN;
    int cntmaxi = 0;
    for(auto i : tasks) {
        mp[i]++;
        if(mp[i] == maxi) {
            cntmaxi++;
        }
        else if(mp[i] > maxi) {
            maxi = mp[i];
            cntmaxi = 1;
        }
    }
    int available = (maxi - 1)*(t - cntmaxi + 1);
    int remain = n - (cntmaxi*maxi);
    int idel = max(0,available - remain);
    return n + idel;
}
// T : O(N * LogN)
// S : O(N)
