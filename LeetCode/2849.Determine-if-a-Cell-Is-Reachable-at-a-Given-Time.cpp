// 2849. Determine if a Cell Is Reachable at a Given Time

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx-fx);
        int dy = abs(sy-fy);
        if(dx==0 && dy==0) return t != 1;
        return max(dx,dy) <= t;
    }
};
