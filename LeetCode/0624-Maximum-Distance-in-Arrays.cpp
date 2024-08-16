// 624. Maximum Distance in Arrays


class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0], biggest = arrays[0].back(), diff = 0;
        for(int i = 1; i < arrays.size(); i++) {
            diff = max(diff, abs(smallest - arrays[i].back()));
            diff = max(diff, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }
        return diff;
    }
};
