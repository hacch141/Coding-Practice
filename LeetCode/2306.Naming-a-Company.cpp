// 2306. Naming a Company

// Brute Force
class Solution {

private:
    bool isValid(string s1, string s2, set<string>& st) {
        swap(s1[0],s2[0]);
        if(st.count(s1) || st.count(s2)) {
            return false;
        }
        return true;
    }

public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        set<string> st;
        for(auto it : ideas) st.insert(it);

        long long ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                string s1 = ideas[i];
                string s2 = ideas[j];
                if(isValid(s1,s2,st)) ans++;
            }
        }
        return ans<<1;
    }
};




// Optimized
