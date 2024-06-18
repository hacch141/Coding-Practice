// 826. Most Profit Assigning Work

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int n = difficulty.size(), m = worker.size();
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i],difficulty[i]});
        }

        sort(jobs.rbegin(),jobs.rend());
        sort(worker.rbegin(),worker.rend());

        int pft = 0, JobPtr = 0, WkrPtr = 0;
        while(JobPtr < n && WkrPtr < m) {
            while(WkrPtr < m && worker[WkrPtr] >= jobs[JobPtr].second) {
                pft += jobs[JobPtr].first;
                WkrPtr++;
            }
            JobPtr++;
        }
        return pft;
    }
};
