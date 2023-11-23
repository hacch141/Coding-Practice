// 1424. Diagonal Traverse II

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> mp;

        int maxi = 0;
        int n = nums.size();
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<nums[i].size(); j++) {
                mp[i+j].push_back(nums[i][j]);
                maxi = max(maxi,i+j);
            }
        }

        vector<int> ans;
        for(int i=0; i<=maxi; i++) {
            for(auto ele : mp[i]) {
                ans.push_back(ele);
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        queue<pair<int,int>> q;
        q.push({0,0});

        vector<int> ans;
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            ans.push_back(nums[row][col]);
            q.pop();
            if(col == 0) {
                if(row+1 < n) q.push({row+1,col});
                if(col+1 < nums[row].size())q.push({row,col+1});
            }
            else {
                if(col+1 < nums[row].size())q.push({row,col+1});
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(int i=0; i<n; i++) {
            for(int j=0; j<nums[i].size(); j++) {
                pq.push({i+j,j});
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            int col = pq.top().second;
            int row = pq.top().first - col;
            pq.pop();
            ans.push_back(nums[row][col]);
        }

        return ans;
    }
};
