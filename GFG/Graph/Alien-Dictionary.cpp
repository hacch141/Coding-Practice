class Solution{
    
    private:
    vector<int> topoSort(int K, vector<int> adj[]) {
        int indegree[K] = {0};
        for(int i=0; i<K; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<K; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for(auto it : adj[curr]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return topo;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0; i<N-1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int cnt = min(s1.length(),s2.length());
            for(int j=0; j<cnt; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K,adj);
        string ans = "";
        for(auto it : topo) {
            ans += it+'a';
        }
        return ans;
    }
};
