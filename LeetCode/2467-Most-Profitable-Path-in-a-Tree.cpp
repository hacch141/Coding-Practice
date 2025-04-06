// 2467. Most Profitable Path in a Tree

class Solution {
public:
    void get_height(int u, int par, int h, vector<vector<int>>& adj, int& bob, int& bob_height, vector<int>& prev) {
        if(u == bob) bob_height = h;
        prev[u] = par;
        for(auto &v : adj[u]) {
            if(v == par) continue;
            get_height(v, u, h + 1, adj, bob, bob_height, prev);
        }
    }

    void rec(int u, int par, vector<vector<int>>& adj, vector<int>& amount, int& curr, int& ans) {
        curr += amount[u];
        for(auto &v : adj[u]) {
            if(v == par) continue;
            rec(v, u, adj, amount, curr, ans);
        }
        if(adj[u].size() == 1 && adj[u][0] == par) ans = max(ans, curr);
        curr -= amount[u];
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> prev(n);
        int bob_height;
        get_height(0, 0, 1, adj, bob, bob_height, prev);

        for(int i = 0; i < (bob_height / 2); i++) {
            amount[bob] = 0;
            bob = prev[bob];
        }

        if(bob_height & 1) amount[bob] /= 2;

        int ans = INT_MIN, curr = 0;
        rec(0, 0, adj, amount, curr, ans);

        return ans;
    }
};

// Code With MIK
//Approach-1 (DFS for Bob and DFS for Alice)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool>&  visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0) { //reached target
            return true;
        }

        for(auto &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                if(DFSBob(ngbr, t+1, visited) == true) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
            income += amount[curr];
        } else if(t == bobMap[curr]) {
            income += (amount[curr]/2);
        }


        if(adj[curr].size() == 1 && curr != 0) { //leaf node
            aliceIncome = max(aliceIncome, income);
        }

        /*
            {1} -> (2, 3)
            2 -> 1
            3 -> 1,....
            (1) ---- (2)
             |
             |
             (3)------.....
        */

        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                DFSAlice(ngbr, t+1, income, visited, amount);
            }
        }

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); //n nodes (0 to n-1)

        aliceIncome = INT_MIN;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS on Bob for finding time to reach each node till 0
        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);

        return aliceIncome;
    }
};


//Approach-2 (DFS for Bob and BFS for Alice)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool>&  visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0) { //reached target
            return true;
        }

        for(auto &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                if(DFSBob(ngbr, t+1, visited) == true) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); //n nodes (0 to n-1)

        aliceIncome = INT_MIN;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS on Bob for finding time to reach each node till 0
        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        int income = 0;
        visited.assign(n, false);

        //BFS se karunga
        queue<vector<int>> que;
        //{node, time, income}
        que.push({0, 0, 0});
        
        while(!que.empty()) {
            int curr = que.front()[0];
            int t = que.front()[1];
            int income = que.front()[2];

            que.pop();

            if(bobMap.find(curr) == bobMap.end() || bobMap[curr] > t) {
                income += amount[curr];
            } else if(t == bobMap[curr]) {
                income += (amount[curr])/2;
            }

            if(adj[curr].size() == 1 && curr != 0) {
                aliceIncome = max(aliceIncome, income);
            }

            for(int &ngbr : adj[curr]) {
                if(!visited[ngbr]) {
                    que.push({ngbr, t+1, income});
                }
            }

            visited[curr] = true;
        }

        return aliceIncome;
    }
};
