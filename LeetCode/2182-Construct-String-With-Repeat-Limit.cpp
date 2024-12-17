// 2182. Construct String With Repeat Limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> mp;
        for(auto ch : s) mp[ch]++;

        priority_queue<pair<char,int>> pq;
        for(auto i : mp) {
            pq.push(i);
        }

        string ans;
        while(pq.size() >= 2) {
            auto it1 = pq.top();
            pq.pop();

            if(it1.second <= repeatLimit) {
                ans += string(it1.second, it1.first);
            }
            else {
                auto it2 = pq.top();
                pq.pop();

                ans += string(repeatLimit, it1.first);
                it1.second -= repeatLimit;

                ans += it2.first;
                it2.second--;

                if(it1.second > 0) pq.push(it1);
                if(it2.second > 0) pq.push(it2);
            }
        }

        auto it = pq.top();
        pq.pop();
        ans += string(min(it.second, repeatLimit), it.first);
        
        return ans;
    }
};
