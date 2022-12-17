class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue< pair<int,int> > q;
        q.push({0,start});
        vector<int> dist(100000,1e9);
        dist[start] = 0;
        
        while(!q.empty()) {
            int u = q.front().second;
            int steps = q.front().first;
            q.pop();
            
            if(u==end) return steps;
            
            for(auto it : arr) {
                int v = (it*u)%100000;
                if(steps+1 < dist[v]) {
                    dist[v] = steps+1;
                    q.push({dist[v],v});
                }
            }
        }
        return -1;
    }
};
