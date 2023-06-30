// Minimum days to make M bouquets

class Solution {
public:

    void find_MM(vector<int> &bloomDay, int& low, int& high) {
        low = INT_MAX;
        high = INT_MIN;
        for (auto i : bloomDay) {
            low = min(low, i);
            high = max(high, i);
        }
    }

    bool isValid(int M, int K, vector<int> &bloomDay, int mid) {
        int noOfb = 0;
        int cnt = 0;
        for(auto i : bloomDay) {
            if(i <= mid) {
                cnt++;
            }
            else {
                noOfb += (cnt/K);
                cnt = 0;
            }
        }
        noOfb += (cnt/K);
        return noOfb >= M;
    }

    int solve(int M, int K, vector<int> &bloomDay) {
        int n = bloomDay.size();
        if (M * 1LL * K * 1LL > n) {
            return -1;
        }

        int low, high;
        find_MM(bloomDay, low, high);
        
        int ans = high;
        while (low <= high) {
            int mid = (high-low)/2 + low;

            if(isValid(M, K, bloomDay, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// T : O(N + LogN)
// S : O(1)
