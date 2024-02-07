// 451. Sort Characters By Frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto i : s) freq[i]++;
        vector<pair<char, int>> v(freq.begin(), freq.end());

        auto cmp = [&](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        };

        sort(v.begin() , v.end(), cmp);

        string ans = "";
        for(int i = 0; i < v.size(); i++) {
            ans.append(v[i].second , v[i].first);
        }

        return ans;
    }
};


class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for(auto i : s) {
            freq[i]++;
        }
        
        vector<vector<char>> bucket(n+1);
        for(auto [ch, fq] : freq) {
            bucket[fq].push_back(ch);
        }

        string ans = "";
        for(int i = n; i >= 1; i--) {
            for(auto ch : bucket[i]) {
                ans.append(i, ch);
            }
        }

        return ans;
    }
};
