// 1462. Course Schedule IV

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        for (auto &prerequisite : prerequisites) {
            int u = prerequisite[0], v = prerequisite[1];
            isPrerequisite[u][v] = true;
        }
        
        // Floyd-Warshall Algorithm to find transitive closure
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (isPrerequisite[i][k] && isPrerequisite[k][j]) {
                        isPrerequisite[i][j] = true;
                    }
                }
            }
        }
        
        vector<bool> ans;
        for (auto &query : queries) {
            int u = query[0], v = query[1];
            ans.push_back(isPrerequisite[u][v]);
        }
        
        return ans;
    }
};
