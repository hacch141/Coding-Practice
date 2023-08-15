// Isomorphic String

bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
    unordered_map<char,char> mp;
    vector<int> vis(26,0);
    int n1 = str1.length();
    int n2 = str2.length();
    if(n1 != n2) return false;

    for(int i=0; i<n1; i++) {
        if(mp.find(str1[i]) == mp.end()) {
            if(vis[str2[i]-'a'] == 1) return false;
            vis[str2[i]-'a'] = 1;
            mp[str1[i]] = str2[i];
        }
        else {
            if(mp[str1[i]] != str2[i]) {
                return false;
            }
        }
    }

    return true;
}

// T : O(N)
// S : O(1)



/*

	Time complexity: O(N^2)
	Space complexity: O(1)

	where N is length of the string.

*/

bool areIsomorphic(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();

    // Length of both strings must be same for one to one correspondence.
    if (m != n) return false;
    
    for(int i = 0; i < n; i++) {
        // Character 'first' of str1 is mapped to character 'second' of str2.
        char first = str1[i];
        char second = str2[i];

        for(int j = 0; j < m; j++) {
            // 'first' in str1 should be mapped to 'second' in whole string.
            if(str1[j] == first && str2[j] != second) {
                return false;
            }

            // 'second' in str2 should be mapped to 'first'.
            if(str2[j] == second && str1[j] != first) {
                return false;
            }
        }
    }

    return true;
}

// T : O(N^2)
// S : O(1)
