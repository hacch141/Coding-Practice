// City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        for(auto i : edges) {
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        
        for(int i=0; i<n; i++) dist[i][i] = 0;
        
        for(int v=0; v<n; v++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
                }
            }
        }
        
        int mini = INT_MAX;
        int city = -1;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= mini) {
                mini = cnt;
                city = i;
            }
        }
        
        return city;
    }
};

// T : O(V^3)
// S : O(V^2)
