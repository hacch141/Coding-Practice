// 2998. Minimum Number of Operations to Make X and Y Equal

class Solution {
public:

    int minimumOperationsToMakeEqual(int x, int y) {
        if(x <= y) return y - x;
        queue<pair<int,int>> q;
        q.push({x , 0});
        unordered_set<int> vis;

        while(1) {
            int e = q.front().first;
            int c = q.front().second;
            q.pop();

            if(e == y) return c;

            if(e % 11 == 0 && !vis.count(e / 11)) {
                vis.insert(e / 11);
                q.push({e / 11, c + 1});
            }

            if(e % 5 == 0 && !vis.count(e / 5)) {
                vis.insert(e / 5);
                q.push({e / 5, c + 1});
            }

            if(e + 1 <= x + 11 && !vis.count(e + 1)) {
                vis.insert(e + 1);
                q.push({e + 1, c + 1});
            }

            if(e - 1 >= 1 && !vis.count(e - 1)) {
                vis.insert(e - 1);
                q.push({e - 1, c + 1});
            }
        }
        return 0;
    }
};
