// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = s.length();
        while(right < n) {
            if(mpp[s[right]] != -1) {
                left = max(mpp[s[right]]+1,left);
            }
            mpp[s[right]] = right;
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};



// ==========================================================


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0, r=0, n=s.length(), ans=0;

        for(r=0; r<n; r++) {
            while(mp.find(s[r]) != mp.end()) {
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]]++;
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
