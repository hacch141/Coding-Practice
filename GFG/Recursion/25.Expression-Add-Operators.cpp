// Expression Add Operators

class Solution {
public:

    void solve(int ind, int &n, int &target, string &num, string currstr, vector<string> &ans, long long prev, long long total) {
        if(ind == n) {
            if(total == target) {
                ans.push_back(currstr);
            }
            return;
        }
        

        long long curr = 0;
        string st = "";
        for(int i=ind; i<n; i++) {

            if(i>ind && num[ind]=='0') break;

            curr = (curr*10) + (num[i]-'0');
            st += num[i];

            if(ind == 0) {
                solve(i+1,n,target,num,currstr+st,ans,curr,curr);
            }
            else {
                solve(i + 1, n, target, num, currstr + '+' + st, ans, curr, total + curr);
                solve(i + 1, n, target, num, currstr + '-' + st, ans, -curr, total - curr);
                solve(i + 1, n, target, num, currstr + '*' + st, ans, prev*curr, total - prev + (prev * curr));
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        int n = num.length();
        vector<string> ans;
        string currstr = "";
        solve(0,n,target,num,currstr,ans,0,0);
        return ans;
    }
};
// T : O(3^n)
// S : O(n^2)
