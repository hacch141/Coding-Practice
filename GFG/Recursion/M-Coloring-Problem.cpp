class Solution{
    
private:

    bool isValid(int col, int color[], int node, bool graph[101][101], int n) {
        for(int i=0; i<n; i++) {
            if(node!=i && graph[i][node]==1 && color[i]==col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int color[], bool graph[101][101], int m, int n) {
        // if we reached at last node
        if(node == n) {
            return true;
        }
        // try for all combination of the colors
        for(int i=1; i<=m; i++) {
            if(isValid(i,color,node,graph,n)) {
                color[node] = i;
                if(solve(node+1,color,graph,m,n)) return true;
                color[node] = 0;
            }
        }
        // if there is no any possible color for node
        return false;
    }
    
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        return solve(0,color,graph,m,n);
    }
};
