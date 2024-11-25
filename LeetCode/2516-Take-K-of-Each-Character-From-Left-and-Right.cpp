// 2516. Take K of Each Character From Left and Right

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length(), ans = INT_MAX;
        vector<int> cnt(3, 0);
        int left, right = n - 1;
        for(int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            if(cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                ans = i + 1;
                left = i;
                break;
            }
        }
        if(ans == INT_MAX) return -1;
        while(left >= 0) {
            cnt[s[left] - 'a']--;
            while(cnt[s[left] - 'a'] < k) {
                cnt[s[right] - 'a']++;
                right--;
            }
            ans = min(ans, left + (n - 1 - right));
            left--;
        }
        return ans;
    }
};
