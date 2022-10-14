// 56. Merge Intervals

class Solution {
public:
    
    static bool compare(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};
        sort(intervals.begin(), intervals.end(), compare);
        int j = 0;
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<n;i++) {
            if(ans[j][1] >= intervals[i][0]) {
                ans[j][1] = max(ans[j][1],intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};
