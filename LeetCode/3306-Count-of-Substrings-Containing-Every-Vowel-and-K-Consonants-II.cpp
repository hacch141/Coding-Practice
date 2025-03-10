// 3306. Count of Substrings Containing Every Vowel and K Consonants II

class Solution {
public:
    bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        vector<int> next_cons(n, n);
        for(int i = n - 2; i >= 0; i--) {
            if(!is_vowel(word[i + 1])) next_cons[i] = i + 1;
            else next_cons[i] = next_cons[i + 1];
        }

        long long ans = 0;
        int left = 0, cnt = 0;
        map<char,int> mp;

        for(int right = 0; right < n; right++) {
            if(is_vowel(word[right])) mp[word[right]]++;
            else cnt++;

            while(cnt > k) {
                if(is_vowel(word[left])) {
                    mp[word[left]]--;
                    if(mp[word[left]] == 0) mp.erase(word[left]);
                }
                else {
                    cnt--;
                }
                left++;
            }

            while(cnt == k && mp.size() == 5) {
                ans += 1LL * (next_cons[right] - right);
                if(is_vowel(word[left])) {
                    mp[word[left]]--;
                    if(mp[word[left]] == 0) mp.erase(word[left]);
                }
                else {
                    cnt--;
                }
                left++;
            }
            
        }

        return ans;
    }
};
