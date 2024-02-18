// 3044. Most Frequent Prime

class Solution {
public:
    
    bool prime[1000000];
    
    int dx[8] = {-1, 0, +1, 0, -1, -1, +1, +1};
    int dy[8] = {0, -1, 0, +1, -1, +1, -1, +1};
    
    unordered_map<int,int> mp;
    
    void help(int i, int j, int& n, int& m, int& dx, int& dy, int num, vector<vector<int>>& mat) {
        num = (num * 10) + mat[i][j];
        if(prime[num] && num > 10) mp[num]++;
        
        int nx = i + dx;
        int ny = j + dy;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
            help(nx, ny, n, m, dx, dy, num, mat);
        }
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        for(int i = 0; i < 1000000; i++) prime[i] = true;
        for(int i = 2; i*i <= 999999; i++) {
            if(prime[i]) {
                for(int j = i*i; j <= 999999; j+=i) {
                    prime[j] = false;
                }
            }
        }
        
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int d = 0; d < 8; d++) {
                    help(i, j, n, m, dx[d], dy[d], 0, mat);
                }
            }
        }
        
        int mxf = 0, ans = -1;
        for(auto i : mp) mxf = max(mxf, i.second);
        for(auto i : mp) {
            if(i.second == mxf) {
                ans = max(ans, i.first);
            }
        }
        
        return ans;
    }
};
