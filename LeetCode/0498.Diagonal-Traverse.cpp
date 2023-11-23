// 498. Diagonal Traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        unordered_map<int,vector<int>> mp;

        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<mat[i].size(); j++) {
                mp[i+j].push_back(mat[i][j]);
                maxi = max(maxi,i+j);
            }
        }

        vector<int> ans;
        for(int i=0; i<=maxi; i++) {
            vector<int> v = mp[i];
            if(i%2 == 0) {
                ans.insert(ans.end(),v.begin(),v.end());
            }
            else {
                ans.insert(ans.end(),v.rbegin(),v.rend());
            }
        }

        return ans;
    }
};
