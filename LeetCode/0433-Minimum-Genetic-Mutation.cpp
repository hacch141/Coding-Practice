// 433. Minimum Genetic Mutation

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st;
        for(auto &s : bank) {
            st.insert(s);
        }

        vector<char> v = {'A', 'C', 'G', 'T'};
        int cnt = 0;
        queue<string> q;
        q.push(startGene);

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string curr = q.front();
                q.pop();
                if(curr == endGene) return cnt;
                for(int i = 0; i < 8; i++) {
                    for(auto &ch : v) {
                        if(ch == curr[i]) continue;
                        string nxt = curr;
                        nxt[i] = ch;
                        if(st.count(nxt)) {
                            q.push(nxt);
                            st.erase(nxt);
                        }
                    }
                }
            }
            cnt++;
        }
        
        return -1;
    }
};
