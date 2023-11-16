// 1980. Find Unique Binary String


// backtracking
class Solution {
public:

    string solve(int n, string& curr, unordered_set<string>& st) {
        if(n == 0) {
            if(st.find(curr) == st.end()) {
                return curr;
            }
            return "";
        }

        curr.push_back('0');
        string take_0 = solve(n-1,curr,st);
        if(take_0 != "") return take_0;
        curr.pop_back();

        curr.push_back('1');
        string take_1 = solve(n-1,curr,st);
        if(take_1 != "") return take_1;
        curr.pop_back();

        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st;
        for(auto i : nums) {
            st.insert(i);
        }

        int n = nums[0].length();
        string curr = "";
        return solve(n,curr,st);
    }
};

// =======================================================================

class Solution {
public:

    int get_num(string s) {
        int num = 0;
        int len = s.length();
        for(int i=len-1; i>=0; i--) {
            if(s[i] == '1') {
                num |= (1<<(len-1-i));
            }
        }
        return num;
    }

    string get_binary(int num, int len) {
        string binary = "";
        for(int i=0; i<len; i++) {
            if(num&1) {
                binary = "1" + binary;
            }
            else {
                binary = "0" + binary;
            }
            num >>= 1;
        }
        return binary;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int len = nums[0].length();
        vector<int> vis(1<<n,0);

        for(int i=0; i<n; i++) {
            int num = get_num(nums[i]);
            vis[num] = 1;
        }

        for(int i=0; i<1<<n; i++) {
            if(!vis[i]) {
                return get_binary(i,len);
            }
        }

        return "";
    }
};
