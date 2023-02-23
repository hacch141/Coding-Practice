// 1011. Capacity To Ship Packages Within D Days

class Solution {

private:
    bool isValid(vector<int>& weights, int days, int mid) {
        int n = weights.size();
        int cnt = 1;
        int curr = 0;

        for(int i=0; i<n; i++) {
            if(curr<=mid && curr+weights[i] <= mid) {
                curr += weights[i];
            }
            else {
                cout << endl << endl;
                curr = weights[i];
                if(curr>mid) return false;
                cnt++;
            }
        }
        return cnt<=days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MAX;
        int high = 0;
        int n = weights.size();
        for(int i=0; i<n; i++) {
            low = min(low,weights[i]);
            high += weights[i];
        }
        while(low <= high) {
            int mid = (high-low)/2 + low;
            if(isValid(weights,days,mid)) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};
