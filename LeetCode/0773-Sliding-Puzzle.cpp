// 773. Sliding Puzzle

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "", target = "123450";
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                start += to_string(board[i][j]);
            }
        }

        map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {3, 5, 1};
        mp[5] = {2, 4};

        queue<string> q;
        q.push(start);
        int lvl = 0;
        set<string> vis;
        vis.insert(start);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string curr = q.front();
                q.pop();
                if(curr == target) return lvl;
                int zero_ind = curr.find('0');
                for(auto swap_ind : mp[zero_ind]) {
                    string new_str = curr;
                    swap(new_str[swap_ind], new_str[zero_ind]);
                    if(!vis.count(new_str)) {
                        q.push(new_str);
                        vis.insert(new_str);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
