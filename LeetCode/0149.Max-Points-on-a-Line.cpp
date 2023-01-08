// 149. Max Points on a Line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPoints = 1;
        int n = points.size();
        for(int i=0; i<n; i++) {
            unordered_map<double,int> mp;
            double x1 = points[i][0];
            double y1 = points[i][1];
            for(int j=0; j<n; j++) {
                if(i != j) {
                    double x2 = points[j][0];
                    double y2 = points[j][1];
                    mp[((y2-y1)/(x2-x1))]++;
                    maxPoints = max(maxPoints,mp[((y2-y1)/(x2-x1))]+1);
                }
            }
        }
        return maxPoints;
    }
};
