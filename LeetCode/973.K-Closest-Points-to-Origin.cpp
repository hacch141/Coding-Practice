// 973. K Closest Points to Origin

class Solution {
public:
    
    struct compare {
        bool operator()(vector<int> &p1, vector<int> &p2) {
            return p1[0] > p2[0];
        }
    };
    
    int findDist(vector<int> &v1) {
        return pow(v1[0],2) + pow(v1[1],2);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {        
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        
        for(auto i : points) {
            pq.push({findDist(i), i[0], i[1]});
        }
        
        while(k--) {
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};
