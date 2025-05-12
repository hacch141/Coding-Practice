// 2094. Finding 3-Digit Even Numbers

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || k == i) continue;
                    int num = 100 * digits[i] + 10 * digits[j] + digits[k];
                    if(num >= 100 && num % 2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }
        vector<int> ans;
        for(auto i : st) ans.push_back(i);
        return ans;
    }
};
