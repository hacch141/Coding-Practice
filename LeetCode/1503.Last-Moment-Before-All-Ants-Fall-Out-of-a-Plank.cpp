// 1503. Last Moment Before All Ants Fall Out of a Plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = INT_MIN;
        int rightMin = INT_MAX;

        for(auto i : left) {
            leftMax = max(leftMax,i);
        }

        for(auto i : right) {
            rightMin = min(rightMin,i);
        }

        return max(leftMax,n-rightMin);
    }
};
