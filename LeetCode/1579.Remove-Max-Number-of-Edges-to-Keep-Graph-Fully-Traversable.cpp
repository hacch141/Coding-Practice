// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

class DSU {
    public:
    vector<int> Parent, Rank;
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu1(n+1);
        DSU dsu2(n+1);
        int ans = 0;
        int edgecnt1 = 0;
        int edgecnt2 = 0;

        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[0] > b[0];
        });

        for(auto edge : edges) {
            if(edge[0]==3) {
                if((dsu1.Find(edge[1]) == dsu1.Find(edge[2])) &&  dsu2.Find(edge[1]) == dsu2.Find(edge[2])) {
                    ans++;
                }
                if(dsu1.Find(edge[1]) != dsu1.Find(edge[2])) {
                    dsu1.Union(edge[1],edge[2]);
                    edgecnt1++;
                }
                if(dsu2.Find(edge[1]) != dsu2.Find(edge[2])) {
                    dsu2.Union(edge[1],edge[2]);
                    edgecnt2++;
                }
            }
            else if(edge[0]==1) {
                if(dsu1.Find(edge[1]) == dsu1.Find(edge[2])) {
                    ans++;
                }
                else {
                    dsu1.Union(edge[1],edge[2]);
                    edgecnt1++;
                }
            }
            else if(edge[0]==2) {
                if(dsu2.Find(edge[1]) == dsu2.Find(edge[2])) {
                    ans++;
                }
                else {
                    dsu2.Union(edge[1],edge[2]);
                    edgecnt2++;
                }
            }
        }
        if(edgecnt1!=n-1 || edgecnt2!=n-1) return -1;
        return ans;
    }
};
