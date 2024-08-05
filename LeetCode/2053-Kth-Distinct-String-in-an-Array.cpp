// 2053. Kth Distinct String in an Array
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        set<string> st, rep;
        for(auto s : arr) {
            if(st.count(s)) rep.insert(s);
            st.insert(s);
        }

        int c = 0;
        for(auto s : arr) {
            if(rep.count(s)) continue;
            c++;
            if(c == k) return s;
        }
        return "";
    }
};
