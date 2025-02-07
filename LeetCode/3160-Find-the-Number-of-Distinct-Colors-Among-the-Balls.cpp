// 3160. Find the Number of Distinct Colors Among the Balls

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ball, color_count;
        vector<int> ans;
        for(auto &q : queries) {
            int cur_ball = q[0], cur_col = q[1];
            if(ball.find(cur_ball) != ball.end()) {
                color_count[ball[cur_ball]]--;
                if(color_count[ball[cur_ball]] == 0) {
                    color_count.erase(ball[cur_ball]);
                }
            }
            color_count[cur_col]++;
            ball[cur_ball] = cur_col;
            ans.push_back(color_count.size());
        }
        return ans;
    }
};
