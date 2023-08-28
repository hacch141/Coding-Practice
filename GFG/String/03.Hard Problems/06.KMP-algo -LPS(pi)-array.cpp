/*
    Time complexity: O(n + m)
    Space complexity: O(m)

    Where 'n' and 'm' are the lengths of 'text' and 'pattern' respectively.
*/

vector<int> stringMatch(string text, string pattern) {

    int n = text.size(), m = pattern.size();

    // List storing the indices of occurrences
    vector<int> ans;

    // Initializing LPS array
    vector<int> lps(m);
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        } else if (j > 0)
            j = lps[j - 1];
        else {
            lps[i] = 0;
            i++;
        }
    }

    i = 0;
    j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else if (j > 0)
            j = lps[j - 1];
        else
            i++;

        // If the pattern matches
        if (j == m) {
            ans.push_back(i - m + 1);
            j = lps[j - 1];
        }
    }

    return ans;
}
// T : O(M+N)
// S : O(len of pattern)
