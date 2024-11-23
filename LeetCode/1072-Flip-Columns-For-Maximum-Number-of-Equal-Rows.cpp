// 1072. Flip Columns For Maximum Number of Equal Rows

class Solution {
public:

    bool check(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        bool f1 = true, f2 = true;
        for(int i = 0; i < n; i++) {
            if(v1[i] != v2[i]) f1 = false;
            if(v1[i] == v2[i]) f2 = false;
        }
        return f1 || f2;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for(int i1 = 0; i1 < n; i1++) {
            int cnt = 0;
            for(int i2 = 0; i2 < n; i2++) {
                cnt += check(matrix[i1], matrix[i2]);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};


class Solution {
public:

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        map<string,int> mp;
        for(auto v : matrix) {
            string s1, s2;
            for(int i = 0; i < m; i++) {
                if(v[i] == 0) s1 += 'F', s2 += 'T';
                else s1 += 'T', s2 += 'F';
            }
            mp[s1]++;
            mp[s2]++;
        }
        for(auto i : mp) {
            ans = max(ans, i.second);
        }
        return ans;
    }
};
