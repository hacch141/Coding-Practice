// City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int INF = (int) 1e9;
        int[][] dist = new int[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd–Warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] < INF && dist[via][j] < INF) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int minCnt = Integer.MAX_VALUE;
        int city = -1;

        // count reachable cities
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            // <= ensures largest index in case of tie
            if (cnt <= minCnt) {
                minCnt = cnt;
                city = i;
            }
        }

        return city;
    }
}

// ================================================================================

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
