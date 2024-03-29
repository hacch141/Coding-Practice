// Palindrome Partitioning

#include <bits/stdc++.h>

bool isPalindrome(string &s, int low, int high) {
    while(low <= high) {
        if(s[low] != s[high]) return false;
        low++;
        high--;
    }
    return true;
}

void solve(int ind, string &s, vector<string> &path, vector<vector<string>> &ans) {
    int n = s.length();

    if(ind == n) {
        ans.push_back(path);
        return;
    }

    for(int i=ind; i<n; i++) {
        if(isPalindrome(s,ind,i)) {
            path.push_back(s.substr(ind,i-ind+1));
            solve(i+1,s,path,ans);
            path.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s) {
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> path;
    solve(0,s,path,ans);
    return ans;
}
// T : O(2^n * n^2)
// S : O(2^n * n)



/*
    Function to recursively generate all possible partitions of a given string 's'.

    Time Complexity:  O(2^n * n).
    Space Complexity: O(2^n * n).

    where n is the length of the input string 's'.
*/


void setPalindromes(string &s , vector<vector<bool>>& dp){
    int n = s.size();
    // Mark single characters as palindromes.
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Mark palindromes of length 2.
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = (s[i] == s[i + 1]);
    }

    // Calculate palindromes for lengths greater than 2.
    for (int d = 2; d <= n - 1; d++) {
        for (int i = 0; i + d < n; i++) {
            dp[i][i + d] = dp[i + 1][i + d - 1] && (s[i] == s[i + d]);
        }
    }

}

void generatePartitions(vector<vector<string>>& ans, vector<string>& current, string& s, int index, vector<vector<bool>>& dp) {
    int n = s.size();

    // Base case: if we have reached the end of the string.
    if (index >= n) {
        ans.push_back(current);
        return;
    }

    // Explore all possible partitions starting from the current index.
    for (int j = index; j < n; j++) {
        // Check if the substring from index 'index' to 'j' is a palindrome.
        if (dp[index][j]) {
            // Add the palindrome substring to the current partition.
            current.push_back(s.substr(index, j - index + 1));

            // Recursively generate partitions for the remaining string.
            generatePartitions(ans, current, s, j + 1, dp);

            // Backtrack and remove the last palindrome substring from the current partition.
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int n = s.length();

    // Initialize the dynamic programming table to store palindrome information.
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    setPalindromes(s , dp);
    vector<vector<string>> ans;
    vector<string> current;

    // Generate all possible partitions of the string.
    generatePartitions(ans, current, s, 0, dp);

    return ans;
}
