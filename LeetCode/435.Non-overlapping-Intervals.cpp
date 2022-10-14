// 435. Non-overlapping Intervals

class Solution {
public:
    
    static bool compare(vector<int> &v1, vector<int> &v2) {
        return v1[1] < v2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> prev = intervals[0];
        int ans = -1;
        for(auto i : intervals) {
            if(prev[1] > i[0]) {
                ans++;
            }
            else {
               prev = i; 
            }
        }
        return ans;
    }
};
