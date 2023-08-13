// Sudoko Solver

bool isValid(int val, int row, int col, int board[][9]) {
    for(int i=0; i<9; i++) {
        if(board[i][col]==val || board[row][i]==val) {
            return false;
        }
    }

    // Think as 3X3 matrix and finding r and c for it
    int r = row/3;
    int c = col/3;

    for(int i=r*3; i<(r*3)+3; i++) {
        for(int j=c*3; j<(c*3)+3; j++) {
            if(board[i][j]==val) {
                return false;
            }
        }
    }

    return true;
}


// remove 2 for loops by this 
// if (row == 9) return true;
// if (col == 9) return helper(board, row + 1, 0);
// if (board[row][col] != 0) return helper(board, row, col + 1);

bool solve(int board[][9]) {
    for(int row=0; row<9; row++) {
        for(int col=0; col<9; col++) {

            if(board[row][col] == 0) {
                for(int val=1; val<=9; val++) {
                    if(isValid(val,row,col,board)) {
                        board[row][col] = val;
                        if(solve(board) == true) return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }

        }
    }
    return true;
}

bool sudokuSolver(int board[][9]) {
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Don't print output and return output as specified in the question
    */
    return solve(board);
}

// T : O(N^(N*N))  || O(9^81)
// S : O(N*N)
