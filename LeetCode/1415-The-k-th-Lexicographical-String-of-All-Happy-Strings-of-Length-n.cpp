// 1415. The k-th Lexicographical String of All Happy Strings of Length n

class Solution {
public:
    void rec(int ind, int& n, string& curr, char prev, vector<string>& v) {
        if(ind == n) {
            v.push_back(curr);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(ch == prev) continue;
            curr.push_back(ch);
            rec(ind + 1, n, curr, ch, v);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> v;
        string curr = "";
        rec(0, n, curr, 'd', v);
        sort(v.begin(), v.end());
        return (v.size() < k) ? "" : v[k - 1];
    }
};
