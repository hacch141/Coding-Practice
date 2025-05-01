// 2071. Maximum Number of Tasks You Can Assign

class Solution {
public:
    bool ok(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        multiset<int> ws;
        for(int i = m - mid; i < m; i++) {
            ws.insert(workers[i]);
        }

        for(int i = mid - 1; i >= 0; i--) {
            auto it = prev(ws.end());
            if(*it >= tasks[i]) {
                ws.erase(it);
            }
            else if(pills > 0) {
                auto it2 = ws.lower_bound(tasks[i] - strength);
                if(it2 != ws.end()) {
                    ws.erase(it2);
                    pills--;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 1, r = min(m, n), ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ok(m, tasks, workers, pills, strength)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
