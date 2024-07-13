// 2751. Robot Collisions

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> v(n, vector<int>(4));
        for(int i = 0; i < n; i++) {
            v[i][0] = positions[i];
            v[i][1] = healths[i];
            v[i][2] = (directions[i] == 'L') ? 0 : 1;
            v[i][3] = i;
        }
        sort(v.begin(),v.end());
        
        stack<vector<int>> st;
        for(int i = 0; i < n; i++) {
            st.push(v[i]);

            while(st.size() > 1) {
                vector<int> v2 = st.top();
                st.pop();
                vector<int> v1 = st.top();
                st.pop();

                if(!(v1[2] == 1 && v2[2] == 0)) {
                    st.push(v1);
                    st.push(v2);
                    break;
                }
                
                if(v1[1] > v2[1]) {
                    v1[1]--;
                    st.push(v1);
                }
                else if(v1[1] < v2[1]) {
                    v2[1]--;
                    st.push(v2);
                }
            }
        }

        vector<pair<int,int>> v2;
        while(!st.empty()) {
            v2.push_back({ st.top()[3], st.top()[1] });
            st.pop();
        }
        sort(v2.begin(), v2.end());

        vector<int> ans;
        for(auto i : v2) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
