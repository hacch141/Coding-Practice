// 726. Number of Atoms

class Solution {
public:

    bool isUpper(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }

    bool isLower(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    string countOfAtoms(string formula) {
        stack<pair<string,int>> st;
        int n = formula.length(), ptr = 0;

        while(ptr < n) {
            char ch = formula[ptr];
            if(isUpper(ch)) {
                string f;
                f.push_back(ch);
                ptr++;
                while(ptr < n && isLower(formula[ptr])) {
                    f.push_back(formula[ptr]);
                    ptr++;
                }
                int cnt = 0;
                while(ptr < n && isDigit(formula[ptr])) {
                    cnt = cnt * 10 + (formula[ptr] - '0');
                    ptr++;
                }
                if(cnt == 0) cnt = 1;
                st.push({f, cnt});
            }
            else if(ch == '(') {
                st.push({"(", 0});
                ptr++;
            }
            else if(ch == ')') {
                ptr++;
                int mul = 0;
                while(ptr < n && isDigit(formula[ptr])) {
                    mul = mul * 10 + (formula[ptr] - '0');
                    ptr++;
                }
                if(mul == 0) mul = 1;

                stack<pair<string,int>> tmp;
                while(st.top().first != "(") {
                    tmp.push(st.top());
                    st.pop();
                }
                st.pop();

                while(!tmp.empty()) {
                    tmp.top().second *= mul;
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
        }

        map<string, int> mp;
        while(!st.empty()) {
            mp[st.top().first] += st.top().second;
            st.pop();
        }

        string ans;
        for(auto i : mp) {
            ans += i.first;
            if(i.second > 1) {
                ans += to_string(i.second);
            }
        }

        return ans;
    }
};
