// Possible Words From Phone Digits

void solve(int idx, string& curr, string& s,
 vector<string>& ans, vector<string>& phone) {
    if(idx == s.size()) {
        ans.push_back(curr);
        return;
    }

    string letters = phone[s[idx]-'0']; 
    for(int i=0; i<letters.size(); i++) {
        curr += letters[i];
        solve(idx+1,curr,s,ans,phone);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string s) {
    // Write your code here.
    vector<string> phone = {"0","1","abc","def","ghi","jkl","mno","pqrs",
    "tuv","wxyz"};

    vector<string> ans;
    string curr = "";

    solve(0,curr,s,ans,phone);
    return ans;
}

// T : O(N * 4^N) => N is the length of the input string s
// S : O(N)
