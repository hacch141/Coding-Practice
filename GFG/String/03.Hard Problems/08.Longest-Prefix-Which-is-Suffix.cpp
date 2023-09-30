// Longest Prefix Which is Suffix

string longestPrefixSuffix(string &str){
    // Write your code here.
    int m = str.length();

    vector<int> lps(m);
    lps[0] = 0;
    int j=0, i=1;
    while(i<m) {
        if(str[i] == str[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0) {
            j = lps[j-1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
    return str.substr(0,lps[m-1]);
}

// T : O(N)
// S : O(N)
