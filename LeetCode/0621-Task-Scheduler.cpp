// 621. Task Scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26,0);
        for(auto ch : tasks) f[ch - 'A']++;
        sort(f.rbegin(),f.rend());
        int ideal = (f[0] - 1) * n;
        for(int i = 1; i < 26; i++) {
            ideal -= min(f[0] - 1, f[i]);
        }
        return tasks.size() + max(0, ideal);
    }
};
