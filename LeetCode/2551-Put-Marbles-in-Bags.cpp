// 2551. Put Marbles in Bags

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(n == 1) return 0;

        long long ans = 0;

        priority_queue<int> pq_mx;
        priority_queue<int, vector<int>, greater<int>> pq_mn;
        for(int i = 0; i < n - 1; i++) {
            pq_mx.push(weights[i] + weights[i + 1]);
            pq_mn.push(weights[i] + weights[i + 1]);
        }

        k--;
        while(k--) {
            ans += pq_mx.top();
            ans -= pq_mn.top();
            pq_mx.pop();
            pq_mn.pop();
        }

        return ans;
    }
};

// ===================================================

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // We collect and sort the value of all n - 1 pairs.
        int n = weights.size();
        vector<int> pairWeights(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            pairWeights[i] += weights[i] + weights[i + 1];
        }

        sort(pairWeights.begin(), pairWeights.end());

        // Get the difference between the largest k - 1 values and the
        // smallest k - 1 values.
        long long answer = 0;
        for (int i = 0; i < k - 1; ++i) {
            answer += pairWeights[n - 2 - i] - pairWeights[i];
        }

        return answer;
    }
};
