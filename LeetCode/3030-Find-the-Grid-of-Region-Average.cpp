// 3030. Find the Grid of Region Average

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0)), cnt(n, vector<int>(m, 0));

        for(int i = 0; i + 2 < n; i++) {
            for(int j = 0; j + 2 < m; j++) {

                bool ok = true;
                int avg = 0;
                for(int x = i; x < i + 2; x++) {
                    for(int y = j; y < j + 3; y++) {
                        if(abs(image[x][y] - image[x + 1][y]) > threshold) {
                            ok = false;
                        }
                    }
                }

                for(int y = j; y < j + 2; y++) {
                    for(int x = i; x < i + 3; x++) {
                        if(abs(image[x][y] - image[x][y + 1]) > threshold) {
                            ok = false;
                        }
                    }
                }

                if(ok) {
                    for(int x = i; x < i + 3; x++) {
                        for(int y = j; y < j + 3; y++) {
                            avg += image[x][y];
                        }
                    }
                    avg /= 9;
                    for(int x = i; x < i + 3; x++) {
                        for(int y = j; y < j + 3; y++) {
                            ans[x][y] += avg;
                            cnt[x][y]++;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(cnt[i][j] == 0) {
                    ans[i][j] = image[i][j];
                }
                else {
                    ans[i][j] /= cnt[i][j];
                }
            }
        }

        return ans;
    }
}; 
