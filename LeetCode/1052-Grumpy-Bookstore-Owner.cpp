// 1052. Grumpy Bookstore Owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sat = 0, n = customers.size();
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) sat += customers[i];
        }

        int mxSat = sat;
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 1) sat += customers[i];
            if(i >= minutes && grumpy[i - minutes] == 1) sat -= customers[i - minutes];
            mxSat = max(mxSat, sat);
        }
        return mxSat;
    }
};
