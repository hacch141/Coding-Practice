// Possible Words From Phone Digits

class Solution
{
    public:
    
    void solve(int idx, int a[], int& N, string curr, vector<string>& ans, vector<string>& keypad) {
        if(idx==N) {
            ans.push_back(curr);
            return;
        }
        string str = keypad[a[idx]];
        for(int i=0; i<str.length(); i++) {
            solve(idx+1,a,N,curr+str[i],ans,keypad);
        }
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr = "";
        solve(0,a,N,curr,ans,keypad);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// T : O(n*4^n)
// S : O(N)
