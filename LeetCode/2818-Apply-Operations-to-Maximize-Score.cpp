// 2818. Apply Operations to Maximize Score

class Solution {
public:
    int num_pow(int num, int pow, int MOD) {
        long long ans = 1, mul = num;
        while(pow > 0) {
            if(pow & 1) {
                ans *= mul;
                ans %= MOD;
            }
            mul = mul * mul;
            mul %= MOD;
            pow >>= 1;
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prime_score(n, 0);

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            for(int j = 2; j * j <= nums[i]; j++) {
                if(num % j == 0) {
                    prime_score[i]++;
                    while(num % j == 0) num /= j;
                }
            }
            if(num > 1) prime_score[i]++;
        }

        vector<int> prev_greater(n, -1), next_greater(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && prime_score[st.top()] < prime_score[i]) {
                next_greater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && prime_score[st.top()] <= prime_score[i]) {
                prev_greater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<vector<int>> v;
        for(int i = 0; i < n; i++) v.push_back({nums[i], i});

        sort(v.rbegin(), v.rend());

        long long ans = 1, MOD = 1e9 + 7;
        int ptr = 0;
        while(ptr < n && k > 0) {
            long long num = v[ptr][0], ind = v[ptr][1];
            long long l_cnt = ind - prev_greater[ind] - 1, r_cnt = next_greater[ind] - ind - 1;
            long long curr_subarray_cnt = (l_cnt + 1) * (r_cnt + 1);
            curr_subarray_cnt = min(curr_subarray_cnt, 1LL * k);
            k -= curr_subarray_cnt;
            ptr++;
            ans *= num_pow(num, curr_subarray_cnt, MOD);
            ans %= MOD;
        }

        return (int)ans;
    }
};
