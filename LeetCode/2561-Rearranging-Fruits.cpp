// 2561. Rearranging Fruits

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int,int> cnt; // store diff of freq for each number
        for(auto i : basket1) cnt[i]++;
        for(auto i : basket2) cnt[i]--;

        int mn = INT_MAX;
        vector<int> toSwap;
        for(auto it : cnt) {
            int diff = abs(it.second);
            mn = min(mn, it.first);
            if(diff & 1) return -1; // if diff is odd means not possible to make it balance
            for(int i = 0; i < diff / 2; i++) { // we only have to swap half diff only so it balance with other half
                toSwap.push_back(it.first);
            }
        }

        sort(toSwap.begin(), toSwap.end()); // we have to add lower ele to ans, so we ignore half big ele ans += min(l, r)
        long long ans = 0;
        for(int i = 0; i < toSwap.size() / 2; i++) {
            ans = (ans + min(toSwap[i], 2 * mn));
        }

        return ans;
    }
};

// ==========================

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());
        long long mn = min(basket1[0], basket2[0]);
        
        vector<long long> v1, v2;
        int p1 = 0, p2 = 0;
        while(p1 < n && p2 < n) {
            if(basket1[p1] == basket2[p2]) { // equal means it already balanced
                p1++;
                p2++;
            }
            else if(basket1[p1] < basket2[p2]) { // take p1 bcz p2 can have balanced ele from basket1
                v1.push_back(basket1[p1]);
                p1++;
            }
            else {  // take p2 bcz p1 can have balanced ele from basket2
                v2.push_back(basket2[p2]);
                p2++;
            }
        }
        while(p1 < n) {
            v1.push_back(basket1[p1]);
            p1++;
        }
        while(p2 < n) {
            v2.push_back(basket2[p2]);
            p2++;
        }

        if(v1.size() & 1) return -1;
        for(int i = 0; i < v1.size(); i += 2) {
            // if it has odd freq, we can't balance them
            if((v1[i] != v1[i + 1]) || (v2[i] != v2[i + 1])) return -1;
        }

        long long ans = 0;
        long long m = v1.size();
        int l1 = 0, l2 = 0;
        int r1 = m - 1, r2 = m - 1;
        while(l1 <= r1 && l2 <= r2) {
            // we can swap two elements direct or by using mn element take min of it and add to ans
            if(v1[l1] <= v2[l2]) {
                ans = ans + min(v1[l1], 2 * mn);
                l1 += 2;
                r2 -= 2;
            }
            else {
                ans = ans + min(v2[l2], 2 * mn);
                l2 += 2;
                r1 -= 2;
            }
        }

        return ans;
    }
};

// ======================================================

