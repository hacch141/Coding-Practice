// 909. Snakes and Ladders

class Solution {
public:
    vector<int> get_1d_board(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> v;
        bool l2r = true;
        for(int i = n - 1; i >= 0; i--) {
            if(l2r) {
                for(int j = 0; j < n; j++) {
                    v.push_back(board[i][j] == -1 ? -1 : board[i][j] - 1);
                }
            }
            else {
                for(int j = n - 1; j >= 0; j--) {
                    v.push_back(board[i][j] == -1 ? -1 : board[i][j] - 1);
                }
            }
            l2r = !l2r;
        }
        return v;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> board_1d = get_1d_board(board);
        int n = board_1d.size();
        
        queue<pair<int,int>> q;
        q.push({0, 0});

        vector<bool> vis(n, false);
        vis[0] = true;

        while(!q.empty()) {
            auto it = q.front();
            int curr = it.first, cnt = it.second;
            if(curr == n - 1) return cnt;
            q.pop();
            for(int i = 1; i <= 6; i++) {
                int nxt = curr + i;
                if(nxt >= n) continue;

                if(board_1d[nxt] != -1) nxt = board_1d[nxt];
                if(vis[nxt]) continue;

                q.push({nxt, cnt + 1});
                vis[nxt] = true;
            }
        }

        return -1;
    }
};
