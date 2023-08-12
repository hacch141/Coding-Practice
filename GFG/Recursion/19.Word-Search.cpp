// Word Search

class Solution {
public:

    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, -1, 0, +1};

    bool dfs(int row, int col, int& n, int& m, vector<vector<char>>& board,  string& word, int ind) {
        if(ind == word.size()) {
            return true;
        }
        char ch = board[row][col];
        board[row][col] = '*';
        for(int del=0; del<4; del++) {
            int nRow = row + delRow[del];
            int nCol = col + delCol[del];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && board[nRow][nCol]==word[ind]) {
                if(dfs(nRow,nCol,n,m,board,word,ind+1) == true) return true;
            }
        }
        board[row][col] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i,j,n,m,board,word,1) == true) return true;
                }
            }
        }

        return false;
    }
};

// T : O(N*M * 4^L)   L = LenOfWord
// S : O(L)
