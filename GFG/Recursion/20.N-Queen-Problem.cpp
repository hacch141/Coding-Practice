// N-Queen Problem

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



