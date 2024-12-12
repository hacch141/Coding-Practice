// 2558. Take Gifts From the Richest Pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        multiset<int> st;
        for(auto i : gifts) st.insert(i);
        while(k-- && !st.empty()) {
            int mx = *st.rbegin();
            st.erase(st.find(mx));
            if(mx != 1) st.insert(sqrt(mx));
            else ans++;
        }
        for(auto i : st) ans += i;
        return ans;
    }
};
