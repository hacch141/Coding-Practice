// 3071. Minimum Operations to Write the Letter Y on a Grid

class Solution {
public:

    bool isY(int r, int c, int n) {
        if((r <= n / 2) && (c == r || r + c == n - 1)) return true;
        return (r > n / 2) && (c == n / 2);
    }

    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        map<int,int> mp1, mp2;
        int n = grid.size(), s1 = 0, s2 = 0, ans = 1e4;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isY(i, j, n)) mp1[grid[i][j]]++, s1++;
                else mp2[grid[i][j]]++, s2++;
            }
        }
        for(int i = 0; i < 3; i++) {
            mp1[i] = s1 - mp1[i];
            mp2[i] = s2 - mp2[i];
        }
        int c1 = mp1[0] + min(mp2[1],mp2[2]);
        int c2 = mp1[1] + min(mp2[0],mp2[2]);
        int c3 = mp1[2] + min(mp2[0],mp2[1]);
        return min(c1 , min(c2,c3));
    }
};
