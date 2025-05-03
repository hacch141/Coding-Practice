// 1007. Minimum Domino Rotations For Equal Row

class Solution {
public:
    int min_rot(int val, vector<int>& tops, vector<int>& bottoms) {
        int tp = 0, bt = 0, n = tops.size();
        for(int i = 0; i < n; i++) {
            if(tops[i] != val && bottoms[i] != val) return -1;
            else if(tops[i] == val && bottoms[i] == val) continue;
            else if(tops[i] == val) bt++;
            else tp++;
        }
        return min(tp, bt);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res1 = min_rot(tops[0], tops, bottoms);
        int res2 = min_rot(bottoms[0], tops, bottoms);
        if(res1 == -1 || res2 == -1) return max(res1, res2);
        return min(res1, res2);
    }
};
