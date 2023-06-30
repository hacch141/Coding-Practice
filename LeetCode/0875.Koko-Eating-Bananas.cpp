// 875. Koko Eating Bananas

class Solution {
public:

    int find_maxi(vector<int>& piles) {
        int maxi = INT_MIN;
        for(auto i : piles) {
            maxi = max(maxi,i);
        }
        return maxi;
    }

    bool isValid(vector<int>& piles, int h, int mid) {
        double time = 0;
        for(auto i : piles) {
            time += ceil((double)i/(double)mid);
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = find_maxi(piles);
        int ans = high;

        while(low <= high) {
            int mid = (high-low)/2 + low;

            if(isValid(piles,h,mid)) {
                ans = min(ans,mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
