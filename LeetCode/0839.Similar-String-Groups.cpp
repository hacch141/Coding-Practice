// 839. Similar String Groups

// DFS
class Solution {
public:

    void dfs(int idx, string currStr, vector<string>& strs, vector<bool>& vis, int& n) {
        vis[idx] = true;
        for(int i=0; i<n; i++) {
            if(!vis[i] && isValid(currStr,strs[i])) {
                dfs(i,strs[i],strs,vis,n);
            }
        }
    }

    bool isValid(string& s1, string& s2) {
        int cnt = 0;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) cnt++;
        }
        return cnt==0 || cnt==2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<bool> vis(n,false);
        int ans = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i,strs[i],strs,vis,n);
                ans++;
            }
        }

        return ans;
    }
};


// BFS
class Solution {
public:

    void bfs(int idx, string currStr, vector<string>& strs, vector<bool>& vis, int& n) {
        vis[idx] = true;
        queue<int> q;
        q.push(idx);

        while(!q.empty()) {
            string s = strs[q.front()];
            q.pop();
            for(int i=0; i<n; i++) {
                if(!vis[i] && isValid(s,strs[i])) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    bool isValid(string& s1, string& s2) {
        int cnt = 0;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) cnt++;
        }
        return cnt==0 || cnt==2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<bool> vis(n,false);
        int ans = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                bfs(i,strs[i],strs,vis,n);
                ans++;
            }
        }

        return ans;
    }
};
