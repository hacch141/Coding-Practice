// 1861. Rotating the Box

class Solution {
public:

    vector<vector<char>> rotate_clockwise(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> box2(m, vector<char>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                box2[j][n - 1 - i] = box[i][j];
            }
        }
        return box2;
    }

    void fall_down(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        for(int j = 0; j < m; j++) {
            int bottom = n - 1;
            for(int i = n - 1; i >= 0; i--) {
                if(box[i][j] == '*') {
                    bottom = i - 1;
                }
                else if(box[i][j] == '#') {
                    while(i < bottom && box[bottom][j] != '.') bottom--;
                    if(box[bottom][j] == '.') swap(box[i][j], box[bottom][j]);
                }
            }
        }
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> box2 = rotate_clockwise(box);
        fall_down(box2);
        return box2;
    }
};
