// 1921. Eliminate Maximum Number of Monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        for(int i=0; i<n; i++) {
            dist[i] = ceil((float)dist[i]/(float)speed[i]);
        }

        sort(dist.begin(),dist.end());

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(i+1 <= dist[i]) {
                ans++;
            }
            else {
                break;
            }
        }

        return ans;
    }
};
