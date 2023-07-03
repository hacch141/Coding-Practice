// 859. Buddy Strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1 = s.length();
        int n2 = goal.length();

        if(n1 != n2) return false;

        if(s == goal) {
            set<char> st(s.begin(),s.end());
            return st.size() < n2;
        }

        int ind1=-1, ind2=-1;

        for(int i=0; i<n1; i++) {
            if(s[i] != goal[i]) {
                if(ind1 == -1) {
                    ind1 = i;
                }
                else {
                    ind2 = i;
                    break;
                }
            }
        }

        if(ind2 == -1) return false;

        swap(s[ind1],s[ind2]);

        return s == goal;
    }
};
