// 2509. Cycle Length Queries in a Tree

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q : queries) {
            int a = q[0], b = q[1], cnt = 0;
            while(a != b) {
                if(a > b) {
                    a /= 2;
                }
                else {
                    b /= 2;
                }
                cnt++;
            }
            ans.push_back(cnt + 1);
        }

        return ans;
    }
};

// 
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q : queries) {
            int a = q[0], b = q[1];
            vector<int> path1, path2;
            while(a) {
                path1.push_back(a);
                a /= 2;
            }
            while(b) {
                path2.push_back(b);
                b /= 2;
            }
            reverse(path1.begin(), path1.end());
            reverse(path2.begin(), path2.end());
            int p1 = 0, p2 = 0;
            while(p1 < path1.size() && p2 < path2.size() && path1[p1] == path2[p2]) {
                p1++;
                p2++;
            }
            ans.push_back(path1.size() - p1 + path2.size() - p2 + 1);
        }

        return ans;
    }
};
