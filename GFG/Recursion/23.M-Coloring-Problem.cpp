// M Coloring Problem

#include <bits/stdc++.h>

bool isValid(int node, int col, vector<int> &color, vector<vector<int>> &mat) {
    for(int i=0; i<mat[0].size(); i++) {
        if(mat[node][i]==1 && color[i]==col) {
            return false;
        }
    }

    return true;
}

bool solve(int node, vector<int> &color, int &m, vector<vector<int>> &mat, int &v) {
    if(node == v) {
        return true;
    }

    for(int i=1; i<=m; i++) {
        if(isValid(node,i,color,mat)) {
            color[node] = i;
            if(solve(node+1,color,m,mat,v) == true) return true;
            color[node] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int v = mat.size();
    vector<int> color(v,0);
    return solve(0,color,m,mat,v) == true ? "YES" : "NO";
}
// T : O(M^V)
// S : O(N)
