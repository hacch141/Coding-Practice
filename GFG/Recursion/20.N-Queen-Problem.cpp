// N-Queen Problem

#include <bits/stdc++.h>

void addToAns(vector<vector<int>> &board, vector<vector<int>> &ans, int &n) {
    vector<int> v;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            v.push_back(board[i][j]);
        }
    }
    ans.push_back(v);
}

void solve(int col, int &n, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &leftRow, vector<int> &upperDG, vector<int> &lowerDG) {
    if(col == n) {
        addToAns(board,ans,n);
        return;
    }

    for(int row=0; row<n; row++) {
        if(leftRow[row]==0 && lowerDG[row+col]==0 && upperDG[n-1+col-row]==0) {
            board[row][col] = 1;

            leftRow[row] = 1;
            lowerDG[row+col] = 1;
            upperDG[n-1+col-row] = 1;

            solve(col+1,n,board,ans,leftRow,upperDG,lowerDG);

            upperDG[n-1+col-row] = 0;
            lowerDG[row+col] = 0;
            leftRow[row] = 0;
            
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n,0));

    vector<int> leftRow(n,0), upperDG(2*n-1,0), lowerDG(2*n-1,0);

    solve(0,n,board,ans,leftRow,upperDG,lowerDG);
    return ans;
}
// T : O(n^n)
// S : O(2*n)






#include <bits/stdc++.h>

void addToAns(vector<vector<int>> &board, vector<vector<int>> &ans, int &n) {
    vector<int> v;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            v.push_back(board[i][j]);
        }
    }
    ans.push_back(v);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int &n) {
    int r = row;
    int c = col;

    // upper diagonal
    while(r>=0 && c>=0) {
        if(board[r][c] == 1) {
            return false;
        }
        r--;
        c--;
    }

    // left
    r = row;
    c = col;
    while(c>=0) {
        if(board[r][c] == 1) {
            return false;
        }
        c--;
    }

    // lower diagonal
    c = col;
    while(r<n && c>=0) {
        if(board[r][c] == 1) {
            return false;
        }
        r++;
        c--;
    }

    return true;
}

void solve(int col, int &n, vector<vector<int>> &board, vector<vector<int>> &ans) {
    if(col == n) {
        addToAns(board,ans,n);
        return;
    }

    for(int row=0; row<n; row++) {
        if(isSafe(row,col,board,n)) {
            board[row][col] = 1;
            solve(col+1,n,board,ans);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n,0));
    solve(0,n,board,ans);
    return ans;
}
// T : O(n^n * n)
// S : O(n^n)


// ==================================================
// Leetcode

class Solution{
public:

    bool isSafe(int row, int col, int n, vector<vector<char>>& board) {
        int r = row;
        int c = col;
        
        while(r>=0) {
            if(board[r][c]=='Q') return false;
            r--;
        }
        
        r = row;
        while(c>=0 && r>=0) {
            if(board[r][c]=='Q') return false;
            r--;c--;
        }
        
        r = row;
        c = col;
        while(r>=0 && c<n) {
            if(board[r][c]=='Q') return false;
            r--;c++;
        }
        
        return true;
    }

    void solve(int row, int n, vector<vector<char>>& board, vector<int>& curr, vector<vector<int>>& ans) {

        if(row==n) {
            ans.push_back(curr);
            return;
        }
        
        for(int col=0; col<n; col++) {
            if(isSafe(row,col,n,board)) {
                curr.push_back(col+1);
                board[row][col] = 'Q';
                solve(row+1,n,board,curr,ans);
                board[row][col] = '.';
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        vector<vector<char>> board(n, vector<char>(n,'.'));
        solve(0,n,board,curr,ans);
        return ans;
    }
};
