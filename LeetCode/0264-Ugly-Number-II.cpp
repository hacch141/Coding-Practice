// 264. Ugly Number II

// DP
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> seq(n);
        seq[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; i++) {
            seq[i] = min({2 * seq[p2], 3 * seq[p3], 5 * seq[p5]});
            if(seq[i] == 2 * seq[p2]) p2++;
            if(seq[i] == 3 * seq[p3]) p3++;
            if(seq[i] == 5 * seq[p5]) p5++;
        }
        return seq[n - 1];
    }
};

// MinHeap (prefer this easy to explain)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> primes = {2, 3, 5};
        unordered_set<long long> vis;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        pq.push(1);
        vis.insert(1);

        long long curr;
        for(int i = 0; i < n; i++) {
            curr = pq.top();
            pq.pop();
            for(auto p : primes) {
                if(!vis.count(curr * p)) {
                    pq.push(curr * p);
                    vis.insert(curr * p);
                }
            }
        }

        return (int)curr;
    }
};
