// Sum of Beauty of all substring

class Solution {
    public static int getBeautyNumber(int freq[]){
        int mx = 0;
        int mn = Integer.MAX_VALUE;
        for (int i = 0; i < freq.length; i++) {
            if (freq[i] != 0) {
                mx = Math.max(mx, freq[i]);
                mn = Math.min(mn, freq[i]);
            }
        }
        return (mn == Integer.MAX_VALUE) ? 0 : (mx - mn);
    }

    public int beautySum(String s) {
        int beautySum = 0;
        for (int i = 0; i < s.length(); i++) {
            int freq[] = new int[26];
            for (int j = i; j < s.length(); j++) {
                freq[s.charAt(j) - 'a']++;
                beautySum += getBeautyNumber(freq);
            }
        }

        return beautySum;
    }
}

// ========================================================================

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0; i<n; i++) {
            vector<int> freq(26,0);
            int maxi=1, mini=1e9;
            for(int j=i; j<n; j++) {
                int ind = s[j] - 'a';
                freq[ind]++;
                if(freq[ind] > maxi) maxi = freq[ind];
                mini = 1e9;
                for(int k=0; k<26; k++) {
                    if(freq[k] >= 1) mini = min(mini,freq[k]);
                }
                if(j>i) ans += (maxi-mini);
            }
        }

        return ans;
    }
};
// T : O(N*N*26)
// S : O(1)



/*
    Time Complexity: O( N^2* max(N,K) )
    Space Complexity: O( N^3 )

    Where 'N' is the string 'S' length and
    'K' is the number of lowercase English letters.
*/

void generateSubString(string &s, vector<string>&subStrings) {
    int n = s.length();
    for (int i = 0; i < n; i++) {

        // Start with an empty string.
        string cur = "";
        for (int j = i; j < n; j++) {

            // Add current character to the substring.
            cur.push_back(s[j]);

            // Add the substring to the array.
            subStrings.push_back(cur);
        }
    }
}

int sumOfBeauty(string s) {

    // Generate all substrings and store them in an array of strings, 'subStrings'.
    vector<string>subStrings;

    // Generate all the substrings.
    generateSubString(s, subStrings);

    // Initialize an integer variable 'answer' with 0.
    int answer = 0;

    for (string &subString : subStrings) {
        // Initialize an integer array 'freq' of length 26 with 0.
        vector<int>freq(26, 0);

        for (char c : subString) {
            // Increment 'freq[i-'a']' by one.
            freq[c - 'a']++;
        }

        // Calculate the value of 'maxFrequency' and 'minFrequency'.
        int maxFrequency = 0, minFrequency = INT_MAX;
        for (int i = 0; i < 26; i++) {
            maxFrequency = max(maxFrequency, freq[i]);
            if (freq[i]) {
                minFrequency = min(minFrequency, freq[i]);
            }
        }

        // Add the beauty of current substring to 'answer'.
        answer += maxFrequency - minFrequency;
    }

    // Return the 'answer'.
    return answer;
}
